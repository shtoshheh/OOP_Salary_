#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include"Booker.h"
#include"Employee.h"
#include"Validation.h"
#include<Windows.h>
using namespace std;

void Booker::make_report(vector<Employee> emp) {
	ofstream fout;
	double all_sal = 0;
	fout.open("report.txt",ios::app);
	fout << "\t\t\t���� � ������� ���������� �����" << endl;
	fout << "-----------------------------------------------------------------------" << endl;
	fout << "|                       ���                        | ���������� ����� |" << endl;
	fout << "-----------------------------------------------------------------------" << endl;
	for (Employee el : emp) {
		fout << "|" << setw(43) << el.fio << setw(8) << "|" << setw(13) << el.salary << setw(6) << "|" << endl;
		fout << "-----------------------------------------------------------------------" << endl;
		all_sal += el.salary;
	}
	time_t t = time(NULL);
	tm tm;
	localtime_s(&tm, &t);
	fout << "\n����: " << tm.tm_mday << "." << tm.tm_mon + 1 << "." << tm.tm_year + 1900 << "    �����: " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << "      ����� ���������: " << all_sal << "\n\n\n";
}

	


void Booker::calculate() {
	try {
		Employee e;
		vector<Employee> emp;
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
		if (emp.empty()) throw 1;
		else {
			for (int i = 0; i < emp.size();i++) {
				double okl_sum, prem_sum = emp[i].prem, sick_sum = 0;
				if (emp[i].hours > 170) {
					okl_sum = emp[i].okl;
					prem_sum += (emp[i].hours - 170) / 170. * emp[i].okl * 1.2;
				}
				else okl_sum = emp[i].hours / 170. * emp[i].okl;
				if (emp[i].sick_days != 0) {
					sick_sum = 8 * emp[i].sick_days / 170. * emp[i].okl * 0.8;
				}
				emp[i].salary = 0.86 * (okl_sum + prem_sum + sick_sum - emp[i].fine);
			}
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
			make_report(emp);
			cout << "\n\t\t\t\t���������� ����� ����������� ���������� �������!\n";
			system("pause");
			system("cls");
		}
	}
	catch (int) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
	
}
void Booker :: best_worker_award(){
	try {
		Employee e;
		vector<Employee> emp;
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
		Employee max = emp[0];
		for (Employee el : emp)
			if (el.hours > max.hours) max = el;
		cout << "\n\t\t\t���������, ������������ ���������� ���������� �����: " << max.fio << endl;
		cout << "\n\t\t\t\t\t��������� ������?\n";
		cout << "\t\t\t\t\t1 - ��\n";
		cout << "\t\t\t\t\t2 - ���\n";
		int ch;
		Validation::input_num(ch);
		while (ch > 2) { 
			cout << "\n\t\t\t\t������� ���������� ��������!\n";
			Validation::input_num(ch);
		}
		if (ch == 1) {
			ifstream fin;
			fin.open("prem_fund.txt");
			double fund;
			fin >> fund; fin.get();
			fin.close();
			cout << "\t\t\t\t������� ������ ������: ";
			double prem;
			Validation::input_num(prem);
			while (prem > 0.5 * max.okl) {
				cout << "\n\t\t\t\t������ �� ����� ��������� " << max.okl * 0.5 << " ������(50% ������)! ������� ���������� ��������!\n";
				Validation::input_num(prem);
			}
			if (fund - prem < 0) {
				cout << "\n\t\t\t\t\t������������ ������� � ����������� �����! ��������� ����!\n";
				system("pause");
				system("cls");
				return;
			}
			for (int i = 0; i < emp.size(); i++)
				if (emp[i].fio == max.fio)
					emp[i].prem += prem;
			fund -= prem;
			ofstream fout;
			fout.open("prem_fund.txt", ios::trunc);
			fout << fund;
			fout.close();
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
			cout << "\n\t\t\t\t������ ���������� " << max.fio << " ��������� �������!\n";
			system("pause");
			system("cls");
		}
		else {
			system("cls");
			return; }

	}
	catch (double) {
		cout << "\n\t\t\t\t\t���������� �����������!\n";
		system("pause");
		system("cls");
	}
}

void Booker :: late_fine(){
	try {
		Employee e;
		vector<Employee> emp;
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
		if (emp.empty()) throw 1.3;
		view_emp();
		cout << "������� ����� ����������, �������� ������ ��������� �����: ";
		int n;
		int find = 0;
		Validation::input_num(n);
		for (int i = 0; i < emp.size(); i++) {
			if (i == n - 1) {
				find = 1;
				cout << "\t\t\t\t������� ������ ������: ";
				double fine;
				Validation::input_num(fine);
				while (fine > 0.5 * emp[i].okl) {
					cout << "\n\t\t\t\t����� �� ����� ��������� " << emp[i].okl * 0.5 << " ������(50% ������)! ������� ���������� ��������!\n";
					Validation::input_num(fine);
				}
				emp[i].fine = fine;
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
				cout << "\n\t\t\t\t����� ���������� " << emp[i].fio << " �������� �������!\n";
				system("pause");
				system("cls");
			}
		}
		if (find == 0) throw 1;

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

void Booker :: top_up_fund() {
	vector<Employee> emp;
	Employee e;
	ifstream fin;
	fin.open("prem_fund.txt");
	double fund;
	fin >> fund; fin.get();
	fin.close();
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
	cout << "\t\t\t\t������� ���������� ������� � ����������� �����: " << fund << endl;
	cout << "\n\t\t\t\t\t��������� ����?\n";
	cout << "\t\t\t\t\t1 -��\n";
	cout << "\t\t\t\t\t2 -���\n";
	int ch;
	Validation::input_num(ch);
	while (ch < 1 || ch > 2) {
		cout << "\n\t\t\t\t\t������� ���������� ��������!\n";
		Validation::input_num(ch);
	}
	if (ch == 1) {
		cout << "\n\t\t\t\t������� ������ ����������: ";
		double plus;
		Validation::input_num(plus);
		if (emp.empty()) {
			if (fund + plus > 1000) {
				while (fund + plus > 1000) {
					cout << "\t\t��� ���������� ����������� ������ ������������ ����� �� ����� ��������� 1000 ������!\n\t\t������� ���������� ��������!\n";
					Validation::input_num(plus);
				}
			}
		}
		else {
			double all_okl = 0;
			for (Employee el : emp)
				all_okl += el.okl;
			if (fund + plus > 0.5 * all_okl) {
				while (fund + plus > 0.5 * all_okl) {
					cout << "\t\t\t������ ������������ ����� �� ����� ��������� " << 0.5 * all_okl << "(50% �� ������ ������ �����������)!\n\t\t\t������� ���������� ��������!\n";
					Validation::input_num(plus);
				}

			}
		}
		fund += plus;
		ofstream fout;
		fout.open("prem_fund.txt",ios::trunc);
		fout << fund;
		cout << "\n\t\t\t\t\t����������� ���� �������� �������!\n";
		system("pause");
		system("cls");
	}
	else {
		system("cls");
		return;
	}
}

void Booker :: menu() {
	Booker B;
	while (true) {
		cout << "\n\t\t\t\t\t\t���� ����������\n" << endl;
		cout << "\t\t\t\t\t1 - ��������� ������ �� ������� ���������" << endl;
		cout << "\t\t\t\t\t2 - ��������� ����� �� ���������" << endl;
		cout << "\t\t\t\t\t3 - ���������� ���������� ����� �����������" << endl;
		cout << "\t\t\t\t\t4 - ��������� ����������� ����" << endl;
		cout << "\t\t\t\t\t0 - �����" << endl;
		int choice;
		Validation::input_num(choice);
		while (choice > 4) {
			cout << "\t\t\t\t\t\t������� ���������� ��������!\n";
			Validation::input_num(choice);
		}
		if (choice == 1)
			B.best_worker_award();
		else if (choice == 2)
			B.late_fine();
		else if (choice == 3)
			B.calculate();
		else if (choice == 4)
			B.top_up_fund();
		else { 
			system("cls");
			break; }
	}
}