#pragma once
#include <iostream>
#include <string>

class SNEAKY_CONTACT {
private:
	std::string f_name;
	std::string l_name;
	int rating;
	bool second_date_worthy;

public:
	void set_f_name(std::string name);
	void set_l_name(std::string name);
	void set_rating(int val);
	void set_second_date_worthy(bool yah_or_nah);
	std::string get_f_name();
	std::string get_l_name();
	int get_rating();
	bool get_second_date_worthy();
};
