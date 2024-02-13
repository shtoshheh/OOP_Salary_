#include "Registration.h"
#include"Hash.h"
#include"User.h"
#include <iostream>
#include <fstream>
#include<conio.h>

string Registration::getPass() {
	string pass;
	char symbol;
	const char BACKSP = 8;
	const char ENTER = 13;
	while (true) {
		symbol = _getch();
		if (symbol == BACKSP && pass.size() > 0) {
			pass.pop_back();
			cout << "\b \b";
		}
		else if (symbol == ENTER)
			return pass;
		else if (symbol > 32) {
			pass += symbol;
			cout << "*";
		}
	}
}

void Registration::RegistrationFunction()
{
	try {
		User U;
		Hash hash;
		cout << "\n\t\t\t\t\t\tРЕГИСТРАЦИЯ\n" << endl;
		cout << "\t\t\t\t\tВведите логин: "; cin >> LoginUser;
		cout << "\t\t\t\t\tВведите пароль:"; PasswordUser = getPass(); cout << endl;
		if (LoginUser == "booker" && PasswordUser == "booker") throw 1;
		ifstream fin;
		fin.open("admin_data.txt");
		while (fin.peek() != EOF)
		{
			fin >> U.reg.LoginUser; fin.get();
			fin >> U.reg.PasswordUser; fin.get();
			if (LoginUser == U.reg.LoginUser && to_string(hash.getHash(PasswordUser)) == U.reg.PasswordUser) throw 1.3;
		}
		fin.close();
		fin.open("user_data.txt");
		while (fin.peek() != EOF)
		{
			fin >> U.reg.LoginUser; fin.get();
			fin >> U.reg.PasswordUser; fin.get();
			if (LoginUser == U.reg.LoginUser && to_string(hash.getHash(PasswordUser)) == U.reg.PasswordUser) throw 'q';
		}
		fin.close();
		ofstream fout;
		fout.open("user_data.txt", ios::app);
		fout << LoginUser << endl;
		fout << hash.getHash(PasswordUser) << endl;
		fout.close();
		system("pause");
		system("cls");
	}
	catch (int) {
		cout << "\n\t\t\t\t\tПользователь уже зарегистрирован под ролью бухгалтера!\n";
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\tПользователь уже зарегистрирован под ролью администратора!\n";
		system("pause");
		system("cls");
	}
	catch (char) {
		cout << "\n\t\t\t\t\tПользователь уже зарегистрирован!\n";
		system("pause");
		system("cls");
	}
}

void Registration::EnterToProgram()
{
	Hash hash;
	system("cls");
	string log, pass;
	ifstream fin;
	int find = 0;
	cout << "\n\t\t\t\t\t\tВХОД В ПРОГРАММУ\n\n";
	cout << "\t\t\t\t\tЛогин: "; cin >> log;
	cout << "\t\t\t\t\tПароль: "; pass = getPass();
	fin.open("admin_data.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		Access = 0;
	}
	else {
		while (fin.peek() != EOF) {
			long long file_hash;
			fin >> LoginUser; fin.get();
			fin >> file_hash; fin.get();
			if (log == LoginUser && hash.getHash(pass) == file_hash) {
				Access = 1;
				Role = 1;
				find = 1;
				break;
			}
		}
		system("cls");
	}
	fin.close();
	if(find == 0) {
		fin.open("user_data.txt");
		if (!fin.is_open()) {
			cout << "Ошибка открытия файла!" << endl;
			Access = 0;
		}
		else {
		if (log == "booker" && pass == "booker") {
		Access = 2; Role = 0;
		}
		else {
			while (fin.peek() != EOF) {
				long long file_hash;
				fin >> LoginUser; fin.get();
				fin >> file_hash; fin.get();
				if (log == LoginUser && hash.getHash(pass) == file_hash) {
					Access = 1;
					Role = 0;
					break;
				}
				else { Access = 0; Role = 0; }
			}
			fin.close();
		}
		}
		system("cls");
	}
}
