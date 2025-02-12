#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"
class FileManager : public DataSourceInterface {
private:
	static void addClient(Client client) {
		FilesHelper::saveClient(client);
	}
	static void addEmployee(Employee employee) {
		FilesHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", employee);
	}
	static void addAdmin(Admin admin) {
		FilesHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
	}
	static void getAllClients() {
		FilesHelper::getClients();
	}
	static void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	static void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	static void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
	}
	static void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
	}
	static void removeAllAdmins() {
		FilesHelper::clearFile("Admins.txt", "AdminLastId.txt");
	}
public:
	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	static void updateClients() {
		removeAllClients();
		for (client = allClients.begin(); client != allClients.end(); client++) addClient(*client);
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (employee = allEmployees.begin(); employee != allEmployees.end(); employee++) addEmployee(*employee);
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (admin = allAdmins.begin(); admin != allAdmins.end(); admin++) addAdmin(*admin);
	}
};