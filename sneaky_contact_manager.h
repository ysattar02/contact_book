#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include "sneaky_contact.h"

class sneaky_contact_manager{
public: 
	void add_sneaky_link();
	void display_sneaky_links();
private:
	std::vector<SNEAKY_CONTACT> sneaky_people;
};

