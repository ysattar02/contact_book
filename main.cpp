#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "contact.h"
#include "contact_manager.h"
#include "sneaky_contact.h"
#include "sneaky_contact_manager.h"
using namespace std;

//start global space
sneaky_contact_manager s_contact_manager;
CONTACT_MANAGER contact_manager;
//end global space

int print_menu() {
	cout << "Enter 1 for New Contact: " << endl
		<< "Enter 2 for All Contacts: " << endl
		<< "Enter 3 to Delete a New Contact: " << endl
		<< "Enter 4 to Favorite/Unfavorite an Exisiting Contact: " << endl 
		<< "Enter 5 to Quit the Program: " << endl;
	int u_choice = 0;
	cin >> u_choice;
	while (cin.fail()) {
		cout << "Invalid Input, Try Again: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> u_choice;
	}
	return u_choice;
}

int sneaky_print_menu() {
	cout << "Enter 1 for New Sneaky Link: " << endl
		 << "Enter 2 for Current Sneaky Links: " << endl
		 << "Enter 3 for Main Menu: " << endl;
	int u_choice;
	cin >> u_choice;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "ERROR: DATA TYPE MISMATCH: TRY AGAIN: ";
		cin >> u_choice;
	}
	return u_choice;
}

void sneaky_menu() {
	int u_choice = sneaky_print_menu();
	if (u_choice == 1) {
		s_contact_manager.add_sneaky_link();
	}
	else if (u_choice == 2) {
		s_contact_manager.display_sneaky_links();
	}
	else if (u_choice == 3) {
		system("cls");
		return;
	}
	sneaky_menu();
}


int main() {
	bool load_flag = contact_manager.load_data();
	if (load_flag == 0) {
		cerr << "LOAD_OPERATION_FAILED_CODE_0011002" << endl;
		return -1;
	}
	int u_choice = -1;
	while (u_choice != 4) {
		u_choice = print_menu();
		if (u_choice == 1) {
			contact_manager.create_contact();
		}
		else if (u_choice == 2) {
			contact_manager.display_contacts();
		}
		else if (u_choice == 3) {
			bool status = contact_manager.delete_contact();
			if (status == 0) {
				cerr << "Delete Operation Failed" << endl;
			}
		}
		else if (u_choice == 4) {
			cerr << "Program Terminating..." << endl;
			return 0;
		}
		else if (u_choice == 69) {
			system("cls");
			cout << "Have Thou No Morals!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			system("cls");
			sneaky_menu();
		}
		else {
			cout << "Unknown Selection..." << endl;
		}
	}
	return 0;
}


