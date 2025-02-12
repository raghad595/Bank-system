#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Client:public Person {
private:
	double balance;
public:
	Client():Person() {
		balance = 0;
	}
	Client(int id, string name, string pass, double balance):Person(id, name, pass) {
		set_balance(balance);
	}
	void set_balance(double balance) {
		if (Validation::valid_Balance(balance))
			this->balance = balance;
		else
			cout << "Invalid password!\n";
	}
	double get_balance() { return balance; }
	void deposit(double amount) {
		if (amount > 0)
			this->balance += amount;
		else
			cout << "Insufficient amount!\n";
	}
	void withdraw(double amount) {
		if (amount <= balance && amount > 0)
			this->balance -= amount;
		else
			cout << "Insufficient amount!\n";
	}
	void transferTo(double amount, Client& recipient) {
		withdraw(amount);
		recipient.deposit(amount);
	}
	void checkBalance() {
		cout << "Balance= " << balance << endl;
	}
	void print() {
		Person::print();
		cout << "Balance= " << balance << endl;
	}
};