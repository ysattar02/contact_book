#pragma once
#include <string>

class CONTACT{
private:
	int id;
	std::string f_name = "";
	std::string l_name = "";
	std::string address = "";
	std::string dob = "";
	std::string phone_number = "";
	int fav_flag = 0;
public: 
	void set_f_name(std::string name);
	void set_l_name(std::string name);
	void set_address(std::string addy);
	void set_dob(std::string bday);
	void set_phone_number(std::string digits);
	void set_id(int id);
	void set_favorite(int fav_status);
	std::string get_f_name();
	std::string get_l_name();
	std::string get_address();
	std::string get_dob();
	std::string get_phone_number();
	int get_favorite_status();
	int get_id();
};

