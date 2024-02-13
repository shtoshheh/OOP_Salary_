#pragma once
#include"Employee.h"
#include"Menu.h"
#include<vector>
class Booker : public Employee,public Menu{
	double prem_fund = 0;
	string log = "booker";
	string pass = "booker";
public:
	void menu();
	void best_worker_award();
	void late_fine();
	void calculate();
	void make_report(vector<Employee> emp);
	void top_up_fund();
	
};