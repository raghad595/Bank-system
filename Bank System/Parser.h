#pragma once
#include <sstream>
#include <vector>
#include "Admin.h"
class Parser {
private:
	static vector<string> split(string line) {
		stringstream stream(line);
		string token;
		vector<string> info;
		while (getline(stream, token, '&')) info.push_back(token);
		return info;
	}
public:
	static Client parseToClient(string line) {
		vector<string> info = split(line);
		Client client;
		client.set_id(stoi(info[0]));
		client.set_name(info[1]);
		client.set_pass(info[2]);
		client.set_balance(stod(info[3]));
		return client;
	}
	static Employee parseToEmployee(string line) {
		vector<string> info = split(line);
		Employee employee;
		employee.set_id(stoi(info[0]));
		employee.set_name(info[1]);
		employee.set_pass(info[2]);
		employee.set_Salary(stod(info[3]));
		return employee;
	}
	static Admin parseToAdmin(string line) {
		vector<string> info = split(line);
		Admin admin;
		admin.set_id(stoi(info[0]));
		admin.set_name(info[1]);
		admin.set_pass(info[2]);
		admin.set_Salary(stod(info[3]));
		return admin;
	}
};
