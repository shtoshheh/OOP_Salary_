#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee
{
public:
	string position;
	string fio;
	int hours;
	int expirience;
	double okl;
	int sick_days;
	double salary;
	double fine;
	double prem;

public:
	void add_emp();
	void delete_emp();
	void edit_emp();
	void view_emp();
	void view_sal_data();
	void search_emp();
	void sort_emp();
	void filtr_emp();
	friend istream& operator >>(istream& s, Employee& e);
	friend ostream& operator <<(ostream& s, Employee& e);
	
};
