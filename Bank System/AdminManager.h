#pragma once
#include "EmployeeManager.h"

class AdminManager {
private:
	static void printAdminMenu() {
		system("cls");
		cout << "1.Show my data\n"
			<< "2.Update Password\n"
			<< "3.Add new client\n"
			<< "4.Search for client"
			<< "5.List all clients\n"
			<< "6.Edit client info\n"
			<< "7.Add new employee\n"
			<< "8.Search for employee"
			<< "9.List all employee\n"
			<< "10.Edit client info\n"
			<< "11.Logout\n";
	}
	static void back(Admin* admin) {
		cout << endl;
		system("pause");
		AdminOptions(admin);
	}
public:
	static Admin* login(int id, string password) {
		for (admin = allAdmins.begin(); admin != allAdmins.end(); admin++) {
			if (admin->get_id() == id && admin->get_pass() == password) 
				return admin._Ptr;
		}
		return NULL;
	}
	static bool AdminOptions(Admin* admin) {
		printAdminMenu();
		cout << "Your choice is: ";
		Employee e;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			admin->print();
			break;
		case 2:
			ClientManager::updatePassword(admin);
			FileManager::updateAdmins();
			break;
		case 3:
			EmployeeManager::newClient(admin);
			break;
		case 4:
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			EmployeeManager::listAllClients(admin);
			break;
		case 6:
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			e.set_name(Validation::enterName());
			e.set_pass(Validation::enterPassword());
			e.set_Salary(Validation::enterSalary());
			e.set_id(FilesHelper::getLast("EmployeeLastId.txt") + 1);
			admin->addEmployee(e);
			FileManager::updateEmployees();
			cout << "\nEmployee added successfully.\n";
			break;
		case 8:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL) cout << "\nEmployee not found.\n";
			else admin->searchEmployee(id)->print();
			break;
		case 9:
			system("cls");
			cout << "All employees: \n" << endl;
			admin->listEmployee();
			break;
		case 10:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL) cout << "\nEmployee not found.\n";
			else {
				string name = Validation::enterName();
				string  password = Validation::enterPassword();
				double salary = Validation::enterSalary();
				admin->editEmployee(id, name, password, salary);
				FileManager::updateEmployees();
				cout << "\nEmployee info updated.\n";
			}
			break;
		case 11:
			return false;
			break;
		default:
			system("cls");
			AdminOptions(admin);
			return true;
		}
		back(admin);
		return true;
	}
};