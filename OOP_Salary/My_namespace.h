#pragma once
#include<string>

namespace input {

	string enter(string& s) {
		bool check = true;
		while (check) {
			getline(cin, s);
			check = false;
			int kol = 0;
			for (int i = 0; i < s.size(); i++)
				if (s[i] == ' ')
					kol++;
			if (kol == s.size()) {
				check = true;
				cout << "\t\t\t\t\tНеверный ввод!Строка не может быть пустой!Попробуйте еще раз!\n";
			}
			else {
				for (int i = 0; i < s.size(); i++) {
					if ((int(s[i]) < -64 || int(s[i]) > -1)) {
						if (s[i] != ' ' && s[i] != '-') {
							check = true;
							cout << "\t\t\t\t\t\tНеверный ввод!Попробуйте еще раз!\n";
							break;
						}
					}
				}
			}
		}
		return s;
	}

	char enter(char& ch) {
		while (true) {
			cin >> ch;
			if (cin.good() && ch >= -64 && ch < 0)
				break;
			cin.clear();
			cout << "\t\t\t\t\t\tНеверный ввод!Попробуйте еще раз!\n";
		}
		cin.ignore();
		return ch;
	}

	int table() {
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
		int max = emp[0].fio.size();
		for (Employee el : emp) {
			if (el.fio.size() > max)
				max = el.fio.size();
		}
		return max;
	}

	char upper(char ch) {
		if (int(ch) >= -32 && int(ch) <= -1) {
			return char(int(ch) - 32);
		}
		else return ch;
	}
}