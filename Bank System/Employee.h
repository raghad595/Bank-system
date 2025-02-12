#pragma once
#include "Person.h"
#include "Client.h"
//#include "DataSourceInterface.h"
static vector<Client> allClients;
static vector<Client>::iterator client;
class Employee:public Person {
private:
	double salary;
public:
	Employee() : Person() {
		salary = 0;
	}
	Employee(int id, string name, string password, double salary) : Person(id, name, password) {
		set_Salary(salary);
	}
	void set_Salary(double salary) {
		if (Validation::valid_Salary(salary))
			this->salary = salary;
		else 
			cout << "Insufficient salary\n";
	}
	double getSalary() { return salary; }
	void print() {
		Person::print();
		cout << "Salary= " << salary << endl;
	}
	void addClient(Client& c) {
		allClients.push_back(c);
	}
	Client* searchClient(int id) {
		for (client = allClients.begin(); client != allClients.end(); client++) {
			if (client->get_id() == id) return client._Ptr;
		}
		return NULL;
	}
	void listClient() {
		for (client = allClients.begin(); client != allClients.end(); client++) {
			client->print();
			cout << "-------------------------\n";
		}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->set_name(name);
		searchClient(id)->set_pass(password);
		searchClient(id)->set_balance(balance);
	}
};