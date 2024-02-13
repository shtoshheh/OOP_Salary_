#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include<map>
#include<vector>
#include<algorithm>
#include "Admin.h"
#include"User.h"
#include"Employee.h"
#include"Validation.h"
using namespace std;

void Admin::view_all_users()
{
	try {
		User U;
		ifstream fin;
		vector<User>u;
		fin.open("user_data.txt");
		if (!fin.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		else {
			int i = 1;
			while (fin.peek() != EOF)
			{
				fin >> U.reg.LoginUser; fin.get();
				fin >> U.reg.PasswordUser; fin.get();
				u.push_back(U);
			}
			if (u.empty()) throw 1;
			cout << "\t\t\t\t\tАккаунты всех пользователей\n\n";
			cout << "---------------------------------------------------------------------------\n";
			cout << "|  #  |" << setw(15) << "Логин " << setw(15) << " | " << setw(20) << "Пароль " << setw(20) << " | \n";
			cout << "---------------------------------------------------------------------------\n";
			for (User el : u) {
				cout << "|" << setw(4) << i << " |" << setw(14) << el.reg.LoginUser << setw(15) << "|" << setw(30) << el.reg.PasswordUser << setw(10) << "|\n";
				cout << "---------------------------------------------------------------------------\n";
				i++;
			}
		}
		fin.close();
	}
	catch (int) {
		cout << "\n\t\t\t\t\tПользователи не зарегистрированы!\n";
		system("pause");
		system("cls");
	}
}

void Admin::delete_all_users()
{
	try {
		User U;
		vector<User> u;
		ifstream fin;
		fin.open("user_data.txt");
		while (fin.peek() != EOF)
		{
			fin >> U.reg.LoginUser; fin.get();
			fin >> U.reg.PasswordUser; fin.get();
			u.push_back(U);
		}
		fin.close();
		if (u.empty()) throw 1;
		ofstream fout;
		fout.open("user_data.txt", ios::trunc);
		cout << "Аккаунты всех пользователей удалены" << endl;
		system("pause");
		system("cls");
		fout.close();
	}
	catch(int) {
		cout << "\n\t\t\t\t\tПользователи не зарегистрированы!\n";
		system("pause");
		system("cls");
	}
}

void Admin::delete_user()
{
	try {
		User U;
		vector<Registration> r;
		vector<Registration> u;
		ifstream fin;
		fin.open("user_data.txt");
		while (fin.peek() != EOF)
		{
			fin >> U.reg.LoginUser; fin.get();
			fin >> U.reg.PasswordUser; fin.get();
			r.push_back(U.reg);
		}
		fin.close();
		fin.open("request_data.txt");
		while (fin.peek() != EOF)
		{
			fin >> U.reg.LoginUser; fin.get();
			fin >> U.reg.PasswordUser; fin.get();
			u.push_back(U.reg);
		}
		fin.close();
		if (r.empty())throw 1.3;
		view_all_users();
		int del;
		cout << "Введите номер пользователя, которого хотите удалить: ";
		Validation::input_num(del);
		if (del > r.size()) throw 1;
		for (int i = 0; i < u.size(); i++) {
			if (u[i].LoginUser == r[del - 1].LoginUser && u[i].PasswordUser == r[del - 1].PasswordUser) {
				ofstream fout;
				auto pos = u.cbegin();
				u.erase(pos + i);
				fout.open("request_data.txt", ios::trunc);
				for (Registration el : u) {
					fout << el.LoginUser << endl;
					fout << el.PasswordUser << endl;
				}
				fout.close();
			}
		}
		for (int i = 0; i < r.size(); i++) {
			if (i == del - 1) {
				auto it = r.cbegin();
				r.erase(it + i);
			}
		}
		for (Registration el : r) {
			cout << el.LoginUser << endl;
			cout << el.PasswordUser << endl;
		}
		ofstream fout;
		fout.open("user_data.txt", ios::trunc);
		for (int i = 0; i < r.size();i++) {
			fout << r[i].LoginUser << endl;
			fout << r[i].PasswordUser << endl;
		}
		fout.close();
		cout << "\n\t\t\t\t\tПользователь успешно удалён!\n";
		system("pause");
		system("cls");
	}
	catch (int) {
		cout << "\n\t\t\t\t\tТакого пользователя нет!" << endl;
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\tПользователи не зарегистрированы!\n";
		system("pause");
		system("cls");
	}
}


void Admin::confirm() {
	ifstream fin;
	fin.open("request_data.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!";
	}
	else {
		try {
			User U;
			vector<User> users;
			while (fin.peek() != EOF) {
				fin >> U.reg.LoginUser; fin.get();
				fin >> U.reg.PasswordUser; fin.get();
				users.push_back(U);
			}
			fin.close();
			if (users.empty()) throw 1;
			else {
				int i = 0;
				cout << "\t\t\t\tВходящие запросы\n\n";
				cout << "---------------------------------------------------------------------------\n";
				cout << "|  #  |" << setw(15) << "Логин " << setw(15) << " | " << setw(20) << "Пароль " << setw(20) << " | \n";
				cout << "---------------------------------------------------------------------------\n";
				for (User el : users) {
					cout << "|" << setw(4) << i << " |" << setw(14) << el.reg.LoginUser << setw(15) << "|" << setw(30) << el.reg.PasswordUser << setw(10) << "|\n";
					cout << "---------------------------------------------------------------------------\n";
					i++;
				}
				cout << "\t\t\t\tВведите номер пользователя: ";
				int n;
				ofstream fout;
				Validation::input_num(n);
				if (n > users.size()) throw 1.2;
				else{
					cout << "\n\t\t\t\t1 - Подтвердить права доступа\n";
					cout << "\n\t\t\t\t2 - Отклонить права доступа\n";
					cout << "\n\t\t\t\t0 - Назад\n";
					int ch;
					Validation::input_num(ch);
					while(ch > 2) Validation::input_num(ch);
					if (ch == 1) {
						vector<User>u;
						fin.open("user_data.txt");
						while (fin.peek() != EOF) {
							fin >> U.reg.LoginUser; fin.get();
							fin >> U.reg.PasswordUser; fin.get();
							u.push_back(U);
						}
						fin.close(); 
						for (int i = 0; i < u.size(); i++) {
							if(u[i].reg.LoginUser == users[n - 1].reg.LoginUser)
							{ 
								auto pos = u.cbegin();
								u.erase(pos + i);
							}
						}
						fout.open("user_data.txt", ios::trunc);
						for (User el : u) {
							fout << el.reg.LoginUser << endl;
							fout << el.reg.PasswordUser << endl;
						}
						fout.close();
						fout.open("admin_data.txt", ios::app);
						fout << users[n - 1].reg.LoginUser << endl;
						fout << users[n - 1].reg.PasswordUser << endl;
						fout.close();
						auto pos = users.cbegin();
						users.erase(pos + n - 1);
						fout.open("request_data.txt", ios::trunc);
						for (User el : users) {
							fout << el.reg.LoginUser << endl;
							fout << el.reg.PasswordUser << endl;
						}
						fout.close();
						cout << "\t\t\t\tПрава пользователя успешно подтверждены!\n";
						system("pause");
						system("cls");
						
					}
					else if (ch == 2) {
						auto pos = users.cbegin();
						users.erase(pos + n - 1);
						fout.open("request_data.txt", ios::trunc);
						for (User el : users) {
							fout << el.reg.LoginUser << endl;
							fout << el.reg.PasswordUser << endl;
						}
						fout.close();
						cout << "\t\t\t\tПрава пользователя успешно отклонены!\n";
						system("pause");
						system("cls");
					}
					else { 
						system("pause");
						system("cls");
						return; }
				}
				
			}
		}
		catch (int) {
			cout << "\t\t\t\t\tНет входящих запросов!\n";
			system("pause");
			system("cls");
		}
		catch (double) {
			cout << "\t\t\t\t\t\tВведите корректное значение!\n";
			system("pause");
			system("cls");
		}
	}
}

void Admin::menu()
{
	Admin A;
	Employee E;
	while (true)
	{
		cout << "\n\t\t\t\t\t\tМЕНЮ АДМИНИСТРАТОРА\n" << endl;
		cout << "\t\t\t\t\t1 -  Просмотр всех аккаунтов пользователей" << endl;
		cout << "\t\t\t\t\t2 -  Удаление аккаунта пользователя" << endl;
		cout << "\t\t\t\t\t3 -  Удаление всех аккаунтов пользователей" << endl;
		cout << "\t\t\t\t\t4 -  Подтверждение прав администратора" << endl;
		cout << "\t\t\t\t\t5 -  Просмотр данных о сотрудниках" << endl;
		cout << "\t\t\t\t\t6 -  Добавление нового сотрудника" << endl;
		cout << "\t\t\t\t\t7 -  Редактирование данных о сотрудниках" << endl;
		cout << "\t\t\t\t\t8 -  Удаление сотрудника" << endl;
		cout << "\t\t\t\t\t9 -  Поиск сотрудника" << endl;
		cout << "\t\t\t\t\t10 - Просмотр подробных данных о заработной плате сотрудника" << endl;
		cout << "\t\t\t\t\t11 - Сортировка сотрудников" << endl;
		cout << "\t\t\t\t\t12 - Фильтрация сотрудников" << endl;
		cout << "\t\t\t\t\t0 -  Назад" << endl;
		int choice;
		Validation::input_num(choice);
		while (choice > 12) {
			cout << "\t\t\t\t\t\tВведите корректное значение!\n";
				Validation::input_num(choice);
		}
		system("cls");
		if (choice == 1)
			A.view_all_users();
		else if (choice == 2)
			A.delete_user();
		else if (choice == 3)
			A.delete_all_users();
		else if (choice == 4)
			A.confirm();
		else if (choice == 5) {
			E.view_emp();
			system("pause");
			system("cls");
		}
		else if (choice == 6)
			E.add_emp();
		else if (choice == 7)
			E.edit_emp();
		else if (choice == 8)
			E.delete_emp();
		else if (choice == 9)
			E.search_emp();
		else if (choice == 10)
			E.view_sal_data();
		else if (choice == 11)
			E.sort_emp();
		else if (choice == 12)
			E.filtr_emp();
		else
		{
			break;
			system("cls");
		}
	}

}