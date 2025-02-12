#pragma once
#include "FileManager.h"
#include "Validation.h"
#include "DataSourceInterface.h"
class ClientManager {
private:
	static void printClientMenu() {
		system("cls");
		cout << "1.Show my data\n"
			<< "2.Check Balance\n"
			<< "3.Update Password\n"
			<< "4.Withdraw\n"
			<< "5.Deposit\n"
			<< "6.Transfer amount\n"
			<< "7.Logout\n";
	}
	static void back(Client* c) {
		cout << endl;
		system("pause");
		clientOptions(c);
	}
public:
	static void updatePassword(Person* person) {
		person->set_pass(Validation::enterPassword());
		cout << "\nPassword updated succefully!\n";
	}
	static Client* login(int id, string password) {
		for (client = allClients.begin(); client != allClients.end(); client++) {
			if (client->get_id() == id && client->get_pass() == password) return client._Ptr;
		}
		return NULL;
	}
	static bool clientOptions(Client* client) {
		printClientMenu();
		cout << "Your choice is: ";
		Employee e;
		double amount;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			client->print();
			break;
		case 2:
			system("cls");
			client->checkBalance();
			break;
		case 3:
			updatePassword(client);
			FileManager::updateClients();
			break;
		case 4:
			system("cls");
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::updateClients();
			break;
		case 5:
			system("cls");
			cout << "Enter amount to deposit: ";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClients();
			break;
		case 6:
			system("cls");
			cout << "Enter id of the recipient: ";
			cin >> id;
			while (e.searchClient(id) == NULL) {
				system("cls");
				cout << "Invalid id.\n";
				cout << "\nEnter id of the recipient: ";
				cin >> id;
			}
			cout << "\nEnter amount to transfer: ";
			cin >> amount;
			client->transferTo(amount, *e.searchClient(id));
			FileManager::updateClients();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;
		}
		back(client);
		return true;
	}
};