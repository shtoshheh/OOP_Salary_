#pragma once
#include "Menu.h"
#include"Employee.h"

class Admin : public Employee,public Menu
{
public:
	void menu();
	void delete_all_users();
	void delete_user();
	void view_all_users();
	void confirm();
};
