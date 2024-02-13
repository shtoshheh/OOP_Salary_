#pragma once
#include <string>
#include <fstream>
using namespace std;

class Registration
{
public:
	string LoginUser, PasswordUser;
	int Access, Role;
	
	void RegistrationFunction();
	void EnterToProgram();
	string getPass();
};