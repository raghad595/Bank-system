#pragma once
#include <vector>
#include "Employee.h"
//#include "DataSourceInterface.h"
static vector<Admin> allEmployees; //1
static vector<Admin>::iterator employee;
class Admin : public Employee {
public:
	Admin() : Employee() {}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}
	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (employee = allEmployees.begin(); employee != allEmployees.end(); employee++) {
			if (employee->get_id() == id) return employee._Ptr;
		}
		return NULL;
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->set_name(name);
		searchEmployee(id)->set_pass(password);
		searchEmployee(id)->set_Salary(salary);
	}
	void listEmployee() {
		for (employee = allEmployees.begin(); employee != allEmployees.end(); employee++) {
			employee->print();
			cout << "--------------------\n";
		}
	}
};