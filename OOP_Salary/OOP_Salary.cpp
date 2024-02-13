#include <string>
#include <fstream>
#include <iostream>
#include "Registration.h"
#include "Employee.h"
#include "Admin.h"
#include "User.h"
#include "Hash.h"
#include "Booker.h"
#include"Validation.h"
#include<windows.h>
#include<memory>
using namespace  std;

int main()
{
	system("color F0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	Hash h;
	Registration R;
	Registration* r = new Registration;
	shared_ptr<Registration> ptr(r);
	r = &R;
	Admin A;
	User U;
	Booker B;
		while (true)
		{
			cout << "\n\t\t\t\t\t\t\tМЕНЮ\n" << endl;
			cout << "\t\t\t\t\t\t1 - Вход в программу \n\t\t\t\t\t\t2 - Регистрация пользователя \n\t\t\t\t\t\t3 - Выход из программы" << endl;
			Validation::input_num(choice);
			while (choice > 3) {
				cout << "\t\t\t\t\t\tВведите корректное значение!\n";
				Validation::input_num(choice);
			}
			system("cls");
			if (choice == 1) {
				R.EnterToProgram();
				if (R.Access == 1 && R.Role == 1) {
					A.menu();
					R.Role = 0;
					R.Access = 0;
				}
				else if (R.Access == 1 && R.Role == 0) {
					U.user_menu(r);
					R.Role = 0;
					R.Access = 0;
				}
				else if (R.Access == 2 && R.Role == 0) {
					B.menu();
					R.Role = 0;
					R.Access = 0;
				}
				else {
					cout << "Неверный логин или пароль!" << endl;
					system("pause");
	 				system("cls");
				}
			}
			else if (choice == 2)
				R.RegistrationFunction();
			else if (choice == 3)
				break;

		}
	return 0;
}
