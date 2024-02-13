#include "User.h"
#include <iostream>
#include<fstream>
#include<string>
#include "Validation.h"
#include"Menu.h"
#include"Hash.h"
using namespace std;

void User::request(string l,long long p) {
	fstream fout;
	fout.open("request_data.txt", ios::app);
	fout << l << endl;
	fout << p << endl;
	cout << "\t\t\t\t������ �� ��������� ���� �������� �������!\n";
}

void User::user_menu(Registration *r)
{
	User U;
	Employee E;
	Hash h;
	while (true)
	{
		cout << "\n\t\t\t\t\t\t���� ������������\n" << endl;
		cout << "\t\t\t\t\t1 - �������� ������ � �����������" << endl;
		cout << "\t\t\t\t\t2 - ����� �����������" << endl;
		cout << "\t\t\t\t\t3 - ���������� �����������" << endl;
		cout << "\t\t\t\t\t4 - �������� ��������� ������ � ���������� ����� ����������" << endl;
		cout << "\t\t\t\t\t5 - ���������� �����������" << endl;
		cout << "\t\t\t\t\t6 - ������ ���� ��������������" << endl;
		cout << "\t\t\t\t\t0 - �����" << endl;
		int choice;
		Validation::input_num(choice);
		while (choice > 6) {
			cout << "\t\t\t\t\t\t������� ���������� ��������!\n";
			Validation::input_num(choice);
		}
		system("cls");
		if (choice == 1)
			E.view_emp();
		else if (choice == 2)
			E.search_emp();
		else if (choice == 3)
			E.sort_emp();
		else if (choice == 4)
			E.view_sal_data();
		else if (choice == 5)
			E.filtr_emp();
		else if (choice == 6)
			request(r->LoginUser,h.getHash(r->PasswordUser));
		else {
			system("cls");
			break; }
		
	}

}
