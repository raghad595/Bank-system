#pragma once
#include "Admin.h"
#include <vector>

static vector<Admin> allEmployees;
static vector<Admin>::iterator employee;
static vector<Admin> allAdmins;
static vector<Admin>::iterator admin;
class DataSourceInterface {
protected:
	virtual void addClient(Client) = 0;
	virtual void addEmployee(Employee) = 0;
	virtual void addAdmin(Admin) = 0;
	virtual void getAllClients() = 0;
	virtual void getAllEmployees() = 0;
	virtual void getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};