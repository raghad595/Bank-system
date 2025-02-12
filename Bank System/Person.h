#pragma once
#include <iostream>
#include "Validation.h"
using namespace std;
class Person {
private:
	int id;
	string name, pass;
public:
	Person() {
		id = 0;
		name = pass = "";
	}
	Person(int id, string name, string pass) {
		this->id = id;
		set_name(name);
		set_pass(pass);
	}
	void set_id(int id) {
		this->id = id;
	}
	void set_name(string name) {
		if (Validation::valid_name(name))
			this->name = name;
		else
			cout << "Invalid name!\n";
	}
	void set_pass(string pass) {
		if (Validation::valid_pass(pass))
			this->pass = pass;
		else
			cout << "Invalid password!\n";
	}
	int get_id() { return id; }
	string get_name() { return name; }
	string get_pass() { return pass; }
	void print() {
		cout << "ID: " << id << "\nName: " << name << "\nPassword: " << pass << endl;
	}
};