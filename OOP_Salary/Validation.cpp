#include<iostream>
#include<string>
#include"Validation.h"

using namespace std;

int Validation :: input_num(int& num) {
	while (true) {
		cin >> num;
		if (cin.good() && num >= 0) break;
		cin.clear();
		cout << "\t\t\t\t\t\tНеверный ввод!Попробуйте еще раз!\n";
		cin.ignore(32767, '\n');
	}
	cin.ignore();
	return num;
}

double Validation :: input_num(double& num) {
	while (true) {
		cin >> num;
		if (cin.good() && num > 0) break;
		cin.clear();
		cout << "\t\t\t\t\t\tНеверный ввод!Попробуйте еще раз!\n";
		cin.ignore(32767, '\n');
	}
	cin.ignore();
	return num;
}