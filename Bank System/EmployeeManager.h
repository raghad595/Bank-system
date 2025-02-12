#pragma once
#include "ClientManager.h"
class EmployeeManager {
private:
	static void printEmployeeMenu() {
		system("cls");
		cout << "1.Show my data\n"
			<< "2.Update Password\n"
			<< "3.Add new client\n"
			<< "4.Search for client"
			<< "5.List all clients\n"
			<< "6.Edit client info\n"
			<< "7.Logout\n";
	}
	static void back(Employee* employee) {
		cout << endl;
		system("pause");
		employeeOptions(employee);
	}
public:
	static void newClient(Employee* employee) {
		Client client;
		client.set_id(FilesHelper::getLast("ClientLastId.txt") + 1);
		string password;
		client.set_name(Validation::enterName());
		client.set_pass(Validation::enterPassword());
		employee->addClient(client);
		FileManager::updateClients();
		cout << "\nClient added successfully.\n";
	}
	static void searchForClient(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL) 
			cout << "\nClient not found.\n";
		else 
			employee->searchClient(id)->print();
	}
	static void listAllClients(Employee* employee) {
		system("cls");
		cout << "All clients: \n" << endl;
		employee->listClient();
	}
	static void editClientInfo(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL) 
			cout << "\nClient not found.\n";
		else {
			string name = Validation::enterName();
			string password = Validation::enterPassword();
			double balance = Validation::enterBalance();
			employee->editClient(id, name, password, balance);
			FileManager::updateClients();
			cout << "\nClient info updated.\n";
		}
	}
	static Employee* login(int id, string password) {
		for (employee = allEmployees.begin(); employee != allEmployees.end(); employee++) {
			if (employee->get_id() == id && employee->get_pass() == password) 
				return employee._Ptr;
		}
		return NULL;
	}
	static bool employeeOptions(Employee* employee) {
		printEmployeeMenu();
		cout << "Your choice is: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			employee->print();
			break;
		case 2:
			ClientManager::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:
			newClient(employee);
			break;
		case 4:
			searchForClient(employee);
			break;
		case 5:
			listAllClients(employee);
			break;
		case 6:
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			employeeOptions(employee);
			return true;
		}
		back(employee);
		return true;
	}
};
