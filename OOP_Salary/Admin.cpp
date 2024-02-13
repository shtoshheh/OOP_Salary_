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
			cout << "������ �������� �����!" << endl;
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
			cout << "\t\t\t\t\t�������� ���� �������������\n\n";
			cout << "---------------------------------------------------------------------------\n";
			cout << "|  #  |" << setw(15) << "����� " << setw(15) << " | " << setw(20) << "������ " << setw(20) << " | \n";
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
		cout << "\n\t\t\t\t\t������������ �� ����������������!\n";
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
		cout << "�������� ���� ������������� �������" << endl;
		system("pause");
		system("cls");
		fout.close();
	}
	catch(int) {
		cout << "\n\t\t\t\t\t������������ �� ����������������!\n";
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
		cout << "������� ����� ������������, �������� ������ �������: ";
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
		cout << "\n\t\t\t\t\t������������ ������� �����!\n";
		system("pause");
		system("cls");
	}
	catch (int) {
		cout << "\n\t\t\t\t\t������ ������������ ���!" << endl;
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\t������������ �� ����������������!\n";
		system("pause");
		system("cls");
	}
}


void Admin::confirm() {
	ifstream fin;
	fin.open("request_data.txt");
	if (!fin.is_open()) {
		cout << "������ �������� �����!";
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
				cout << "\t\t\t\t�������� �������\n\n";
				cout << "---------------------------------------------------------------------------\n";
				cout << "|  #  |" << setw(15) << "����� " << setw(15) << " | " << setw(20) << "������ " << setw(20) << " | \n";
				cout << "---------------------------------------------------------------------------\n";
				for (User el : users) {
					cout << "|" << setw(4) << i << " |" << setw(14) << el.reg.LoginUser << setw(15) << "|" << setw(30) << el.reg.PasswordUser << setw(10) << "|\n";
					cout << "---------------------------------------------------------------------------\n";
					i++;
				}
				cout << "\t\t\t\t������� ����� ������������: ";
				int n;
				ofstream fout;
				Validation::input_num(n);
				if (n > users.size()) throw 1.2;
				else{
					cout << "\n\t\t\t\t1 - ����������� ����� �������\n";
					cout << "\n\t\t\t\t2 - ��������� ����� �������\n";
					cout << "\n\t\t\t\t0 - �����\n";
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
						cout << "\t\t\t\t����� ������������ ������� ������������!\n";
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
						cout << "\t\t\t\t����� ������������ ������� ���������!\n";
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
			cout << "\t\t\t\t\t��� �������� ��������!\n";
			system("pause");
			system("cls");
		}
		catch (double) {
			cout << "\t\t\t\t\t\t������� ���������� ��������!\n";
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
		cout << "\n\t\t\t\t\t\t���� ��������������\n" << endl;
		cout << "\t\t\t\t\t1 -  �������� ���� ��������� �������������" << endl;
		cout << "\t\t\t\t\t2 -  �������� �������� ������������" << endl;
		cout << "\t\t\t\t\t3 -  �������� ���� ��������� �������������" << endl;
		cout << "\t\t\t\t\t4 -  ������������� ���� ��������������" << endl;
		cout << "\t\t\t\t\t5 -  �������� ������ � �����������" << endl;
		cout << "\t\t\t\t\t6 -  ���������� ������ ����������" << endl;
		cout << "\t\t\t\t\t7 -  �������������� ������ � �����������" << endl;
		cout << "\t\t\t\t\t8 -  �������� ����������" << endl;
		cout << "\t\t\t\t\t9 -  ����� ����������" << endl;
		cout << "\t\t\t\t\t10 - �������� ��������� ������ � ���������� ����� ����������" << endl;
		cout << "\t\t\t\t\t11 - ���������� �����������" << endl;
		cout << "\t\t\t\t\t12 - ���������� �����������" << endl;
		cout << "\t\t\t\t\t0 -  �����" << endl;
		int choice;
		Validation::input_num(choice);
		while (choice > 12) {
			cout << "\t\t\t\t\t\t������� ���������� ��������!\n";
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