#include "contact_manager.h"

void CONTACT_MANAGER::create_contact() {
	system("cls");
	CONTACT person;
	cin.ignore(256, '\n');
	cout << "Enter Contact's First Name: ";
	string first_name = "";
	getline(cin, first_name);
	person.set_f_name(first_name);
	cout << endl << "Enter Contact's Last Name or N/A: ";
	string last_name = "";
	getline(cin, last_name);
	person.set_l_name(last_name);
	cout << endl << "Enter Contact's DOB or N/A: ";
	string dob;
	getline(cin, dob);
	person.set_dob(dob);
	cout << endl << "Enter Contact's Address or N/A: ";
	string address = "";
	getline(cin, address);
	person.set_address(address);
	int id = assign_id();
	person.set_id(id);
	people.insert({ id, person });
	system("cls");
	return;
}

void CONTACT_MANAGER::display_contacts() {
	system("cls");
	if (people.size() == 0) {
		cerr << "Empty Contact Book, Make Some Friends!" << endl << endl;
		return;
	}
	for (auto it = people.begin(); it != people.end(); it++) {
		cout << endl << "----------------------------------------------" << endl;
		//cout << "ID: " << it->first << endl;
		cout << it->second.get_f_name() << " " << it->second.get_l_name() << endl;
		cout << "Phone Number: " << it->second.get_phone_number() << endl;
		cout << "Date Of Birth: " << it->second.get_dob() << endl;
		cout << "Address: " << it->second.get_address() << endl;
		//cout << "fav_status: " << it->second.get_favorite_status() << endl;
		cout << "----------------------------------------------" << endl;
	}
	return;
}

bool CONTACT_MANAGER::delete_contact() {
	system("cls");
	if (people.size() == 0) {
		cerr << "Empty Contact Book, Make Some Friends!" << endl << endl;
		return 0;
	}
	for (auto it = people.begin(); it != people.end(); it++) {
		cout << "ID: " << it->first << " - " << it->second.get_f_name() << " " << it->second.get_l_name() << endl;
	}
	cout << "Enter the ID Of The Contact To Delete From Your Life: ";
	int to_del_id;
	cin >> to_del_id;
	while (cin.fail()) {
		cerr << "Please Enter the ID Correctly: ";
		cin.clear();
		cin.ignore();
		cin >> to_del_id;
	}
	for (auto it = people.begin(); it != people.end(); it++) {
		if (it->first == to_del_id) {
			people.erase(to_del_id);
			return 1;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int CONTACT_MANAGER::assign_id() {
	int id = rand();
	bool uniqueness = verify_id(id);
	while (uniqueness) {
		id = rand();
		uniqueness = verify_id(id);
	}
	return id;
}

bool CONTACT_MANAGER::verify_id(int id) {
	//false = unique id
	if (people.size() == 0) {
		return false;
	}
	auto it = people.find(id);
	if (it != people.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool CONTACT_MANAGER::clear_file(string file_name) {
	bool enable_flag = 0; //set this to zero to stop the clear from happening, set it to 1 to allow the clear
	if (enable_flag == 0) {
		return true;
	}
	fstream ofs;
	ofs.open(file_name, ios::out | ios::trunc);
	ofs << "";
	ofs.close();
	if (ofs.is_open() == true) {
		cerr << "CLOSE_OPERATION_FAILED_CODE_0011003" << endl;
		return false;
	}
	return true;
}

bool CONTACT_MANAGER::load_data() {
	ifstream datafile;
	string file_name = "data.txt";
	datafile.open(file_name);
	if (!datafile.is_open()) {
		cerr << "Failed To Load Data" << endl;
		return false;
	}
	string line = "";
	while (getline(datafile, line, '\n')) {
		stringstream ss(line);
		string token = "";
		vector<string> token_storage;
		while (getline(ss, token, ':')) {
			token_storage.push_back(token);
			//cout << "Token: " << token << endl;
		}
		CONTACT load_person;
		load_person.set_f_name(token_storage.at(0));
		load_person.set_l_name(token_storage.at(1));
		load_person.set_phone_number(token_storage.at(2));
		load_person.set_dob(token_storage.at(3));
		load_person.set_address(token_storage.at(4));
		load_person.set_favorite(stoi(token_storage.at(5)));
		int id = assign_id();
		load_person.set_id(id);
		people.insert({id, load_person});
	}
	datafile.close();
	bool file_cleared_flag = clear_file(file_name);
	if (file_cleared_flag == false) {
		cerr << "CLEAR_OPERATION_FAILED_CODE_0011004" << endl;
		return false;
	}
	return true;
}
