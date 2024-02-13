#pragma once
#include "Employee.h"
#include "Registration.h"
class User 
{
public:
	Registration reg;
	void user_menu(Registration *r);
	void request(string l,long long p);
};
