#include "Employee.h"
#include <iostream>
#include <fstream>
#include <vector>
#include<iomanip>
#include<string>
#include"Validation.h"
#include"My_namespace.h"
#include<algorithm>

Validation v;
istream& operator >>(istream& s, Employee& e) {
	int n;
	string s1 = "> ";
	cout << "������� ��� ����������: ";
	e.fio = s1 + input :: enter(e.fio);
	cout << "������� ��������� ����������: ";
	e.position = s1 + input :: enter(e.position);
	cout << "������� ���������� �����, ������������ �����������: ";
	Validation::input_num(e.hours);
	cout << "������� ���� ������ ����������(�� 0 �� 50): ";
	Validation::input_num(e.expirience);
	while (e.expirience > 50) {
		cout << "\n\t\t\t\t\t������� ���������� ��������\n";
		Validation::input_num(e.expirience);
	}
	cout << "������� ����� � ������(�� 339.83 �� 3000) �� ������(170 �����): ";
	Validation::input_num(e.okl);
	while (e.okl < 339.83 || e.okl > 3000) {
		cout << "\n\t\t\t\t\t������� ���������� ��������\n";
		Validation::input_num(e.okl);
	}
	cout << "������� ����� ���� �����������(�� 0 �� 31): ";
	Validation::input_num(e.sick_days);
	while (e.sick_days > 31) {
		cout << "\n\t\t\t\t\t������� ���������� ��������\n";
		Validation::input_num(e.sick_days);
	}
	return s;
}

ostream& operator <<(ostream& s, Employee& e) {
	s << "\n��� ����������: " << e.fio << endl;
	s << "��������� ����������: " << e.position << endl;
	s << "���������� �����, ������������ �����������: " << e.hours << endl;
	s << "���� ������ ����������: ";
	if (e.expirience != 0) cout << e.expirience << endl;
	else cout << "���" << endl;
	s << "����� � ������ �� ������(170 �����): " << e.okl << endl;
	s << "����� ���� �����������: ";
	if (e.sick_days != 0) cout << e.sick_days << endl;
	else cout << "���" << endl;
	s << "������ ������ � ������: ";
	if (e.fine != 0) cout << e.fine << endl;
	else cout << "���" << endl;
	s << "������ ������ � ������: ";
	if (e.prem != 0) cout << e.prem << endl;
	else cout << "���" << endl;
	s << "���������� ����� ���������� �� �����: " << e.salary << endl;
	return s;
}

void Employee::add_emp() {
	Employee e;
	cin >> e;
	e.prem = e.fine = e.salary = 0;
	ofstream fout;
	fout.open("employee_data.txt", ofstream::app);
	if (!fout) cout << "���������� ������� ����!";
	else {
		fout << e.fio << endl;
		fout << e.position << endl;
		fout << e.hours << endl;
		fout << e.expirience << endl;
		fout << e.okl << endl;
		fout << e.sick_days << endl;
		fout << e.salary << endl;
		fout << e.fine << endl;
		fout << e.prem << endl;
		cout << "\t\t\t\t\t\t��������� �������� �������!\n\n";
		fout.close();
		system("pause");
		system("cls");
	}
}

void Employee::delete_emp() {
	try{
	vector<Employee> emp;
	Employee e;
	ifstream fin;
	fin.open("employee_data.txt");
	string line, line1;
	while (fin.peek() != EOF) {
		fin >> line; getline(fin, line);
		e.fio = line;
		fin >> line; getline(fin, line);
		e.position = line;
		fin >> e.hours; fin.get();
		fin >> e.expirience; fin.get();
		fin >> e.okl; fin.get();
		fin >> e.sick_days; fin.get();
		fin >> e.salary; fin.get();
		fin >> e.fine; fin.get();
		fin >> e.prem; fin.get();
		emp.push_back(e);
	}
	if (emp.empty()) throw 1.3;
	view_emp();
	cout << "������� ����� ����������, �������� ������ �������: ";
	int n;
	Validation::input_num(n);
		int find = 0;
		for (int i = 0; i < emp.size(); i++) {
			if (i == n - 1) {
				find = 1;
				auto pos = emp.cbegin();
				emp.erase(pos + i);
			}
		}
		if (find == 0) throw 1;
		else {
			ofstream fout;
			fout.open("employee_data.txt", ios::trunc);
			for (int i = 0; i < emp.size(); i++) {
				fout << ">" + emp[i].fio << endl;
				fout << ">" + emp[i].position << endl;
				fout << emp[i].hours << endl;
				fout << emp[i].expirience << endl;
				fout << emp[i].okl << endl;
				fout << emp[i].sick_days << endl;
				fout << emp[i].salary << endl;
				fout << emp[i].fine << endl;
				fout << emp[i].prem << endl;
			}
			fout.close();
			cout << "\t\t\t\t\t\t��������� ����� �������!\n\n";
		}
		system("pause");
		system("cls");
	}
	catch (int) {
		cout << "\t\t\t\t\t��������� �� ������!\n\n";
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
}

void Employee::edit_emp() {
	try{
	vector<Employee> emp;
	Employee e;
	ifstream fin;
	fin.open("employee_data.txt");
	string line, line1;
	while (fin.peek() != EOF) {
		fin >> line; getline(fin, line);
		e.fio = line;
		fin >> line; getline(fin, line);
		e.position = line;
		fin >> e.hours; fin.get();
		fin >> e.expirience; fin.get();
		fin >> e.okl; fin.get();
		fin >> e.sick_days; fin.get();
		fin >> e.salary; fin.get();
		fin >> e.fine; fin.get();
		fin >> e.prem; fin.get();
		emp.push_back(e);
	}
	fin.close();
	if (emp.empty()) throw 1.3;
	view_emp();
	cout << "������� ����� ����������, ������ �������� ������ ���������������: ";
	int n;
	Validation::input_num(n);
		int find = 0;
		for (int i = 0; i < emp.size(); i++) {
			if (i == n - 1) {
				find = 1;
				int choice;
					cout << "\n\t\t\t\t\t���� ��������������\n\n";
					cout << "\t\t\t\t\t1 - ���\n";
					cout << "\t\t\t\t\t2 - ���������\n";
					cout << "\t\t\t\t\t3 - ���������� ������������ �����\n";
					cout << "\t\t\t\t\t4 - ���� ������\n";
					cout << "\t\t\t\t\t5 - ����� �� ������\n";
					cout << "\t\t\t\t\t6 - ���������� ���� �����������\n";
					cout << "\t\t\t\t\t0 - �����\n";
					Validation::input_num(choice);
					while (choice > 6) {
						cout << "\t\t\t\t\t������� ���������� ��������!\n";
						Validation::input_num(choice);
					}
					if (choice == 1) {
						cout << "������� ����� ���: ";
						string new_fio;
						input :: enter(new_fio);
						emp[i].fio = " " + new_fio;
						cout << "\t\t\t\t\t��� ��������������� �������!\n";
					}
					else if (choice == 2) {
						cout << "������� ����� ���������: ";
						string new_pos;
						input :: enter(new_pos);
						emp[i].position = " " + new_pos;
						cout << "\t\t\t\t\t��������� ��������������� �������!\n";
					}
					else if (choice == 3) {
						cout << "������� ����� ���������� ������������ �����: ";
						int new_h;
						Validation::input_num(new_h);
						emp[i].hours = new_h;
						cout << "\t\t\t\t\t���������� ������������ ������ ��������������� �������!\n";
					}
					else if (choice == 4) {
						cout << "������� ����� ����� ��� ����� ������: ";
						int new_ex;
						Validation::input_num(new_ex);
						emp[i].expirience = new_ex;
						cout << "\t\t\t\t\t���� ������ �������������� �������!\n";
					}
					else if (choice == 5) {
						cout << "������� ����� ����� � ������ �� ������: ";
						double new_okl;
						Validation::input_num(new_okl);
						emp[i].okl = new_okl;
						cout << "\t\t\t\t\t����� �� ������ �������������� �������!\n";
					}
					else if (choice == 6) {
						cout << "������� ����� ���������� ���� �����������: ";
						int new_s;
						Validation::input_num(new_s);
						emp[i].sick_days = new_s;
						cout << "\t\t\t\t\t���������� ���� ����������� ��������������� �������!\n";
					}
					else break;
					ofstream fout;
					fout.open("employee_data.txt");
					for (int i = 0; i < emp.size(); i++) {
						fout << ">" + emp[i].fio << endl;
						fout << ">" + emp[i].position << endl;
						fout << emp[i].hours << endl;
						fout << emp[i].expirience << endl;
						fout << emp[i].okl << endl;
						fout << emp[i].sick_days << endl;
						fout << emp[i].salary << endl;
						fout << emp[i].fine << endl;
						fout << emp[i].prem << endl;
					}
					fout.close();
				}

			} 
		if (find == 0) throw 1;
		system("pause");
		system("cls");
	}
	catch (int) {
		cout << "\t\t\t\t\t\t��������� �� ������!\n\n";
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
}

void Employee::view_emp() {
	try {
		vector<Employee> emp;
		Employee e;
		ifstream fin;
		fin.open("employee_data.txt");
		string line;
		while (fin.peek() != EOF) {
			fin >> line; getline(fin, line);
			e.fio = line;
			fin >> line; getline(fin, line);
			e.position = line;
			fin >> e.hours; fin.get();
			fin >> e.expirience; fin.get();
			fin >> e.okl; fin.get();
			fin >> e.sick_days; fin.get();
			fin >> e.salary; fin.get();
			fin >> e.fine; fin.get();
			fin >> e.prem; fin.get();
			emp.push_back(e);
		}
		fin.close();
		if (emp.empty()) throw 1.3;
		int plus1, plus2;
		if (input :: table() % 2 == 0) plus1 = plus2 = input::table() / 2;
		else {
			plus1 = input :: table() / 2 + 1;
			plus2 = input :: table() / 2;
		}
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "|  #  |" << setw(3 + plus1) << "���" << setw(5 + plus2) << "|" << setw(15) << "���������" << setw(5) << "|" << setw(17) << "���� ������" << setw(5) << "|" << setw(21) << "����� �� ������" << setw(5) << "|" << setw(22) << "���������� �����" << setw(5) << "|" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < emp.size(); i++) {
			cout << "|" << setw(4) << i + 1 << " |" << setw(3 + input::table()) << emp[i].fio << setw(5) << "|" << setw(15) << emp[i].position << setw(5) << "|" << setw(13);
			if (emp[i].expirience != 0) cout << emp[i].expirience;
			else cout << "���";
			cout << setw(9) << "|" << setw(15) << emp[i].okl << setw(11) << "|" << setw(16) << emp[i].salary << setw(11) << "|" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
}

void Employee::view_sal_data() {
	try {
		vector<Employee> emp;
		Employee e;
		ifstream fin;
		fin.open("employee_data.txt");
		string line;
		while (fin.peek() != EOF) {
			fin >> line; getline(fin, line);
			e.fio = line;
			fin >> line; getline(fin, line);
			e.position = line;
			fin >> e.hours; fin.get();
			fin >> e.expirience; fin.get();
			fin >> e.okl; fin.get();
			fin >> e.sick_days; fin.get();
			fin >> e.salary; fin.get();
			fin >> e.fine; fin.get();
			fin >> e.prem; fin.get();
			emp.push_back(e);
		}
		fin.close();
		if (emp.empty())throw 1.3;
		view_emp();
		cout << "������� ����� ����������, ������ �������� ������ �����������: ";
		int n;
		Validation::input_num(n);
		int find = 0;
		for (int i = 0;i < emp.size();i++) {
				if (i == n - 1) {
					find = 1;
					cout << "\n\t\t\t\t��������� " << emp[i].fio << endl;
					cout << "\t\t\t\t\t���������� �����: " << emp[i].hours << endl;
					cout << "\t\t\t\t\t���� ������: ";
					if (emp[i].expirience != 0) cout << emp[i].expirience << endl;
					else cout << "���" << endl;
					cout << "\t\t\t\t\t����� �� ������: " << emp[i].okl << endl;
					cout << "\t\t\t\t\t����� ���� �����������: ";
					if (emp[i].sick_days != 0) cout << emp[i].sick_days << endl;
					else cout << "���" << endl;
					cout << "\t\t\t\t\t����� ���������: " << emp[i].salary << endl;
					cout << "\t\t\t\t\t������� �������: ";
					if (emp[i].fine != 0) cout << emp[i].fine << endl;
					else cout << "���" << endl;
					cout << "\t\t\t\t\t��������� ������: ";
					if (emp[i].prem != 0) cout << emp[i].prem << endl;
					else cout << "���" << endl;
				}
			}
			if (find == 0) throw 1;
			system("pause");
			system("cls");
	}
	catch (int) {
		cout << "\t\t\t\t\t\t��������� �� ������!\n\n";
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
}

void Employee :: search_emp() {
	try{
	vector<Employee> emp;
	Employee e;
	ifstream fin;
	fin.open("employee_data.txt");
	string line;
	while (fin.peek() != EOF) {
		fin >> line; getline(fin, line);
		e.fio = line;
		fin >> line; getline(fin, line);
		e.position = line;
		fin >> e.hours; fin.get();
		fin >> e.expirience; fin.get();
		fin >> e.okl; fin.get();
		fin >> e.sick_days; fin.get();
		fin >> e.salary; fin.get();
		fin >> e.fine; fin.get();
		fin >> e.prem; fin.get();
		emp.push_back(e);
	}
	fin.close();
	if (emp.empty()) throw 1.3;
	cout << "\n\t\t\t\t\t���� ������\n\n";
	cout << "\t\t\t\t\t1 - �� ���\n";
	cout << "\t\t\t\t\t2 - �� ���������\n";
	cout << "\t\t\t\t\t3 - �� ���������� �����\n";
	cout << "\t\t\t\t\t4 - �� ����� ������\n";
	cout << "\t\t\t\t\t5 - �� ������ �� ������\n";
	cout << "\t\t\t\t\t6 - �� ����� ���� �����������\n";
	cout << "\t\t\t\t\t7 - �� ���������� ������������ �����\n";
	cout << "\t\t\t\t\t8 - �� ������� ������\n";
	cout << "\t\t\t\t\t9 - �� ������� ������\n";
	cout << "\t\t\t\t\t0 - �����\n";
	int choice;
	Validation::input_num(choice);
	while (choice > 9) {
		cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
		Validation::input_num(choice);
	}
	if (choice == 1) {
		string fio;
		cout << "������� ��� �������� ����������: ";
		fio = " " + input::enter(fio);
		int find = 0;
		for (Employee el: emp) {
			if (el.fio == fio) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if (choice == 2) {
		string pos;
		cout << "������� ��������� �������� ����������: ";
		pos = " " + input::enter(pos);
		int find = 0;
		for (Employee el : emp) {
			if (el.position == pos) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if(choice == 3){
		double sal;
		cout << "������� ���������� ����� �������� ����������: ";
		sal = Validation::input_num(sal);
		int find = 0;
		for (Employee el : emp) {
			if (el.salary == sal) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if (choice == 4) {
		int exp;
		cout << "������� ���� ������ �������� ����������: ";
		exp = Validation::input_num(exp);
		int find = 0;
		for (Employee el : emp) {
			if (el.expirience == exp) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if (choice == 5) {
		double okl;
		cout << "������� ����� �������� ����������: ";
		okl = Validation::input_num(okl);
		int find = 0;
		for (Employee el : emp) {
			if (el.okl == okl) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if (choice == 6) {
		int sick;
		cout << "������� ����� ���� ����������� �������� ����������: ";
		sick = Validation::input_num(sick);
		int find = 0;
		for (Employee el : emp) {
			if (el.sick_days == sick) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if (choice == 7) {
		int h;
		cout << "������� ���������� ������������ ����� �������� ����������: ";
		h = Validation::input_num(h);
		int find = 0;
		for (Employee el : emp) {
			if (el.hours == h) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if (choice == 8) {
		double prem;
		cout << "������� ������ ������ �������� ����������: ";
		prem = Validation::input_num(prem);
		int find = 0;
		for (Employee el : emp) {
			if (el.prem == prem) {
				find = 1;
				cout << el;
			}
		}
		if (find == 0) throw 1;
	}
	else if (choice == 9) {
	double fine;
	cout << "������� ������ ������ �������� ����������: ";
	fine = Validation::input_num(fine);
	int find = 0;
	for (Employee el : emp) {
		if (el.fine == fine) {
			find = 1;
			cout << el;
		}
	}
	if (find == 0) throw 1;
}
	else if (choice == 0) {
		system("cls");
		return;
	}
		system("pause");
		system("cls");
	}
	catch (int) {
		cout << "\t\t\t\t\t\t��������� �� ������!\n\n";
	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
	}
}

bool comp_fio(const Employee& e1, const Employee& e2) {
	return e1.fio < e2.fio;
}

bool comp_sal(const Employee& e1, const Employee& e2) {
	return e1.salary < e2.salary;
}

bool comp_exp(const Employee& e1, const Employee& e2) {
	return e1.expirience < e2.expirience;
}

bool comp_okl(const Employee& e1, const Employee& e2) {
	return e1.okl < e2.okl;
}

template<typename T>
void sort(vector<T> v) {
	for (int i = 0; i < v.size(); i++)
		for (int j = i +1; j < v.size() - 1; j++)
			if (v[i] > v[j]) swap(i, j);
}

void Employee::sort_emp() {
	try{
	vector<Employee> emp;
	Employee e;
	ifstream fin;
	fin.open("employee_data.txt");
	string line;
	while (fin.peek() != EOF) {
		fin >> line; getline(fin, line);
		e.fio = line;
		fin >> line; getline(fin, line);
		e.position = line;
		fin >> e.hours; fin.get();
		fin >> e.expirience; fin.get();
		fin >> e.okl; fin.get();
		fin >> e.sick_days; fin.get();
		fin >> e.salary; fin.get();
		fin >> e.fine; fin.get();
		fin >> e.prem; fin.get();
		emp.push_back(e);
	}
	fin.close();
	if (emp.empty()) throw 1.3;
		cout << "\n\t\t\t\t\t���� ����������\n\n";
		cout << "\t\t\t\t\t1 - �� ���\n";
		cout << "\t\t\t\t\t2 - �� ���������� �����\n";
		cout << "\t\t\t\t\t3 - �� ����� ������\n";
		cout << "\t\t\t\t\t4 - �� ������ �� ������\n";
		cout << "\t\t\t\t\t0 - �����\n";
		int choice;
		Validation::input_num(choice);
		while (choice > 4) {
			cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
			Validation::input_num(choice);
		}
		if (choice == 1) sort(emp.begin(), emp.end(), comp_fio);
		else if (choice == 2) sort(emp.begin(), emp.end(), comp_sal);
		else if (choice == 3) sort(emp.begin(), emp.end(), comp_exp);
		else if (choice == 4) sort(emp.begin(), emp.end(), comp_okl);
		else if (choice == 0) {
			system("pause");
			return;
		}
		else throw 1;
		int plus1,plus2;
		if (input::table() % 2 == 0) plus1 = plus2 = input::table() / 2;
		else {
			plus1 = input::table() / 2 + 1;
			plus2 = input::table() / 2;
		}
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "|  #  |" << setw(3 + plus1) << "���" << setw(5 + plus2) << "|" << setw(15) << "���������" << setw(5) << "|" << setw(17) << "���� ������" << setw(5) << "|" << setw(21) << "����� �� ������" << setw(5) << "|" << setw(22) << "���������� �����" << setw(5) << "|" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < emp.size(); i++) {
			cout << "|" << setw(4) << i + 1 << " |" << setw(3 + input::table()) << emp[i].fio << setw(5) << "|" << setw(15) << emp[i].position << setw(5) << "|" << setw(13);
			if (emp[i].expirience != 0) cout << emp[i].expirience;
			else cout << "���";
			cout << setw(9) << "|" << setw(15) << emp[i].okl << setw(11) << "|" << setw(16) << emp[i].salary << setw(11) << "|" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		}
		system("pause");
		system("cls");
	}
	catch (int) {
		cout << "\t\t\t\t\t\t������� ���������� ��������!\n";
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
}

void Employee::filtr_emp() {
	try {
		vector<Employee> emp;
		vector<Employee> filtr;
		Employee e;
		ifstream fin;
		fin.open("employee_data.txt");
		string line;
		while (fin.peek() != EOF) {
			fin >> line; getline(fin, line);
			e.fio = line;
			fin >> line; getline(fin, line);
			e.position = line;
			fin >> e.hours; fin.get();
			fin >> e.expirience; fin.get();
			fin >> e.okl; fin.get();
			fin >> e.sick_days; fin.get();
			fin >> e.salary; fin.get();
			fin >> e.fine; fin.get();
			fin >> e.prem; fin.get();
			emp.push_back(e);
		}
		fin.close();
		if (emp.empty()) throw 1.3;
		cout << "\n\t\t\t\t\t���� ����������\n\n";
		cout << "\t\t\t\t\t1 - �� ���\n";
		cout << "\t\t\t\t\t2 - �� ���������� �����\n";
		cout << "\t\t\t\t\t3 - �� ����� ������\n";
		cout << "\t\t\t\t\t4 - �� ������ �� ������\n";
		cout << "\t\t\t\t\t0 - �����\n";
		int choice;
		Validation::input_num(choice);
		while (choice > 4) {
			cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
			Validation::input_num(choice);
		}
		if (choice == 1) {
			char let1, let2;
			char ch1, ch2;
			cout << "������� �����, � ������� ������ ������(�� � �� �): ";
			input::enter(let1);
			ch1 = input::upper(let1);
			cout << "������� �����, �� ������� ������ ������(�� " << ch1 << " �� �): ";
			input::enter(let2);
			while (input::upper(let2) <= ch1) {
				cout << "\n\t\t\t\t\t������ ����� ������ ���� ������ �� ��������, ��� ������!\n\t\t\t\t\t������� ���������� ��������!\n";
				input::enter(let2);
			}
			ch2 = input::upper(let2);
			for (Employee el : emp)
				if (el.fio[1] >= ch1 && el.fio[1] <= ch2)
					filtr.push_back(el);
		}
		else if (choice == 2) {
			int sal1, sal2;
			cout << "������� �����, � �������� ������ ������: ";
			Validation::input_num(sal1);
			cout << "������� �����, �� �������� ������ ������(�� " << sal1 << "): ";
			Validation::input_num(sal2);
			while (sal2 < sal1) {
				cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
				Validation::input_num(sal2);
			}
			for (Employee el : emp)
				if (el.salary >= sal1 && el.salary <= sal2)
					filtr.push_back(el);
		}
		else if (choice == 3) {
			int ex1, ex2;
			cout << "������� �����, � �������� ������ ������(�� 0 �� 50): ";
			Validation::input_num(ex1);
			while (ex1 > 50) {
				cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
				Validation::input_num(ex1);
			}
			cout << "������� �����, �� �������� ������ ������(�� " << ex1 << " �� 50): ";
			Validation::input_num(ex2);
			while (ex2 < ex1 || ex2 > 50) {
				cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
				Validation::input_num(ex2);
			}
			for (Employee el : emp)
				if (el.expirience >= ex1 && el.expirience <= ex2)
					filtr.push_back(el);
		}
		else if (choice == 4) {
			double okl1, okl2;
			cout << "������� �����, � �������� ������ ������(�� 339.83 �� 3000): ";
			Validation::input_num(okl1);
			while (okl1 < 339.83 || okl > 3000) {
				cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
				Validation::input_num(okl1);
			}
			cout << "������� �����, �� �������� ������ ������(�� " << okl1 << " �� 3000): ";
			Validation::input_num(okl2);
			while (okl2 < okl1 || okl2 > 3000) {
				cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
				Validation::input_num(okl2);
			}
			for (Employee el : emp)
				if (el.okl >= okl1 && el.okl <= okl2)
					filtr.push_back(el);
		}
		else {
			system("cls");
			return;
		}
		if (filtr.empty()) throw 1;
		int plus1, plus2;
		if (input::table() % 2 == 0) plus1 = plus2 = input::table() / 2;
		else {
			plus1 = input::table() / 2 + 1;
			plus2 = input::table() / 2;
		}
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "|  #  |" << setw(3 + plus1) << "���" << setw(5 + plus2) << "|" << setw(15) << "���������" << setw(5) << "|" << setw(17) << "���� ������" << setw(5) << "|" << setw(21) << "����� �� ������" << setw(5) << "|" << setw(22) << "���������� �����" << setw(5) << "|" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < filtr.size(); i++) {
			cout << "|" << setw(4) << i + 1 << " |" << setw(3 + input::table()) << filtr[i].fio << setw(5) << "|" << setw(15) << filtr[i].position << setw(5) << "|" << setw(13);
			if (filtr[i].expirience != 0) cout << filtr[i].expirience;
			else cout << "���";
			cout << setw(9) << "|" << setw(15) << filtr[i].okl << setw(11) << "|" << setw(16) << filtr[i].salary << setw(11) << "|" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
		}
	}
	catch(int) {
		cout << "\n\t\t\t\t\t���������� �� �������!\n";
		system("pause");
		system("cls");
	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
}