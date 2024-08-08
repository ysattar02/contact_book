#pragma once
#include "contact.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class CONTACT_MANAGER {
public: 
	void create_contact();
	void display_contacts();
	bool delete_contact();
	int assign_id();
	bool verify_id(int id);
	bool clear_file(string file_name);
	bool load_data();
private: 
	map<int, CONTACT> people;
};
