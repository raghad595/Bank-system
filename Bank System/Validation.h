#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation {
public:
	static bool valid_name(string name) {
		if (!(name.size() >= 5 && name.size() <= 20)) {
			cout << "Invalid name!\n";
			return false;
		}
		for (int i = 0; i < name.size(); i++) {
			if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')))
				return false;
		}
		return true;
	}
	static bool valid_pass(string pass) {
		if (!(pass.size() >= 8 && pass.size() <= 20)) {
			cout << "Invalid password!\n";
			return false;
		}
		return true;
	}
	static bool valid_Balance(double balance) {
		if (balance < 1500) {
			cout << "Insufficient salary!\n";
			return false;
		}
		return true;
	}
	static bool valid_Salary(double salary) {
		if (salary < 5000) {
			return false;
		}
		return true;
	}
	static string enterName() {
		string name;
		system("cls");
		cout << "Enter name: ";
		getline(cin, name);
		while (!valid_name(name)) {
			system("cls");
			cout << "Invalid name\n";
			cout << "Name must be 5 to 20 alphapetic character!\n";
			cout << "Enter name: ";
			getline(cin, name);
		}
		return name;
	}
	static string enterPassword() {
		string pass;
		system("cls");
		cout << "Enter password: ";
		getline(cin, pass);
		while (!valid_pass(pass)) {
			system("cls");
			cout << "Invalid password\n";
			cout << "Password must be 8 to 20 long!\n";
			cout << "Enter password: ";
			getline(cin, pass);
		}
		return pass;
	}
	static double enterBalance() {
		double balance;
		system("cls");
		cout << "Enter balance: ";
		cin >> balance;
		while (!valid_Balance(balance)) {
			system("cls");
			cout << "Invalid balance\n";
			cout << "Balance must be at least 1500!\n";
			cout << "Enter balance: ";
			cin >> balance;
		}
		return balance;
	}
	static double enterSalary() {
		double salary;
		system("cls");
		cout << "Enter salary: ";
		cin >> salary;
		while (!valid_Salary(salary)) {
			system("cls");
			cout << "Invalid salary\n";
			cout << "Salary must be at least 5000!\n";
			cout << "Enter salary: ";
			cin >> salary;
		}
		return salary;
	}
};