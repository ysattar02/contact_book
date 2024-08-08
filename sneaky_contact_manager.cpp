#include "sneaky_contact_manager.h"

/*
	std::string f_name;
	std::string l_name;
	int rating;
	bool second_date_worthy;
	vector is called sneaky_people
*/

void sneaky_contact_manager::add_sneaky_link() {
	system("cls");
	SNEAKY_CONTACT s_person;
	std::string first_name = "";
	std::string last_name = "";
	int rating;
	bool second_date;

	std::cin.ignore(256, '\n');
	std::cout << std::endl << "Enter Sneaky Link's First Name: ";
	getline(std::cin, first_name);
	std::cout << std::endl << "Enter " << first_name << "'s Last Name: ";
	getline(std::cin, last_name);
	std::cout << std::endl << "Enter a Rating from 0-100 for " << first_name << " " << last_name << ": ";
	std::cin >> rating;
	while (rating > 100 || rating < 0 || std::cin.fail()) {
		//issue with multiple error messages printing out for each character of an invalid input
		std::cout << "Invalid Rating Value (Enter a Value Between 0 And One Hundred): " << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin >> rating;
	}
	std::cout << std::endl << "Is " << first_name << " " << last_name << " Who You Rated (" << rating << ") Second Date Worthy? ";
	//add in error handling
	std::cin >> second_date;

	s_person.set_f_name(first_name);
	s_person.set_l_name(last_name);
	s_person.set_rating(rating);
	s_person.set_second_date_worthy(second_date);
	sneaky_people.push_back(s_person);
	
	system("cls");
	return;
}

void sneaky_contact_manager::display_sneaky_links() {
	system("cls");
	if (sneaky_people.size() == 0) {
		std::cerr << "Empty Sneaky Link List, Do You Not Pull?" << std::endl;
		return;
	}
	for (auto it = sneaky_people.begin(); it != sneaky_people.end(); it++) {
		std::cout << std::endl << "----------------------------------------------" << std::endl;
		std::cout << "Name: " << it->get_f_name() << " " << it->get_f_name() << std::endl;
		std::cout << "Rating: " << it->get_rating() << std::endl;
		std::cout << "Second Date? (Y/N): " << it->get_second_date_worthy() << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
	}
	return;
}
