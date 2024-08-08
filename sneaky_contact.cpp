#include "sneaky_contact.h"

void SNEAKY_CONTACT::set_f_name(std::string name) {
	f_name = name;
}
void SNEAKY_CONTACT::set_l_name(std::string name) {
	l_name = name;
}
void SNEAKY_CONTACT::set_rating(int val) {
	rating = val;
}
void SNEAKY_CONTACT::set_second_date_worthy(bool yah_or_nah) {
	second_date_worthy = yah_or_nah;
}
std::string SNEAKY_CONTACT::get_f_name() {
	return f_name;
}
std::string SNEAKY_CONTACT::get_l_name() {
	return l_name;
}
int SNEAKY_CONTACT::get_rating() {
	return rating;
}
bool SNEAKY_CONTACT::get_second_date_worthy() {
	return second_date_worthy;
}
