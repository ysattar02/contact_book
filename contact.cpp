#include "contact.h"

void CONTACT::set_f_name(std::string name){
	f_name = name;
}
void CONTACT::set_l_name(std::string name) {
	l_name = name;
}
void CONTACT::set_address(std::string addy) {
	address = addy;
}
void CONTACT::set_dob(std::string bday) {
	dob = bday;
}
void CONTACT::set_phone_number(std::string digits) {
	phone_number = digits;
}
void CONTACT::set_id(int id) {
	id = id;
}
void CONTACT::set_favorite(int fav_status) {
	fav_flag = fav_status;
}
std::string CONTACT::get_f_name() {
	return f_name;
}
std::string CONTACT::get_l_name() {
	return l_name;
}
std::string CONTACT::get_address() {
	return address;
}
std::string CONTACT::get_dob() {
	return dob;
}
std::string CONTACT::get_phone_number() {
	return phone_number;
}
int CONTACT::get_id() {
	return id;
}
int CONTACT::get_favorite_status() {
	return fav_flag;
}
