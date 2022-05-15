#include "Menu.h"
void Menu::MainMenu()
{
	int new_hobbies_num, user_choice = 0;
	double new_age;
	char new_gender, usr_input;
	vector<char> new_string;
	vector<char> new_hobby;
	vector<char*> hobbies_lst;
	while (user_choice == 0) {
		cout << "\tPlease choose one of the following options:" << endl;
		cout << "\t==========================================================" << endl;
		cout << "\t1) Add a new client to the database." << endl;
		cout << "\t2) Remove an existing client from the database." << endl;
		cout << "\t3) Print all clients." << endl;
		cout << "\t4) Print all matches for a client." << endl;
		cout << "\t5) Quit the program." << endl;
		cout << "\t==========================================================" << endl;
		cout << "\t> ";
		clean_buff();
		cin >> user_choice;
		switch (user_choice) {

		case 1: {
			cout << "\tPlease Insert new client details:" << endl;
			cout << "\tNew Client ID: > ";
			clean_buff();
			cin >> noskipws;
			while (cin >> usr_input) {
				if ((int)usr_input == '\n')
					break;
				new_string.push_back(usr_input);
			}
			char* new_id_arr = new char[new_string.size() + 1];
			for (int i = 0; i < new_string.size(); i++)
				new_id_arr[i] = new_string[i];
			new_id_arr[new_string.size()] = 0;
			String New_Id(new_id_arr);
			new_string.clear();
			cout << endl;
			cout << "\tNew Client Name: > ";
			clean_buff();
			while (cin >> usr_input) {
				if ((int)usr_input == '\n')
					break;
				new_string.push_back(usr_input);
			}
			char* new_name_arr = new char[new_string.size() + 1];
			for (int i = 0; i < new_string.size(); i++)
				new_name_arr[i] = new_string[i];
			new_name_arr[new_string.size()] = 0;
			String New_Name(new_name_arr);
			cout << endl;
			cout << "\tNew Client Gender (M/F): > ";
			new_string.clear();
			clean_buff();
			cin >> new_gender;
			while ((int)new_gender != 'M' && (int)new_gender != 'F') {
				cout << "\tInvalid gender, Please try again (M/F): >";
				clean_buff();
				cin >> new_gender;
			}
			cout << endl;
			cout << "\tNew Client Age (18+): > ";
			clean_buff();
			cin >> new_age;
			if (new_age < 18) {
				cout << endl << "\t**New client cannot be registered, client must be at least 18 years old.**" << endl << endl;
				user_choice = 0;
				break;
			}
			cout << endl;
			cout << "\tNew Client Number Of Hobbies: > ";
			clean_buff();
			cin >> new_hobbies_num;
			for (int i = 0; i < new_hobbies_num; i++) {
				cout << endl;
				cout << "\tPlease Enter Hobby #" << i + 1 << ": > ";
				clean_buff();
				while (cin >> usr_input) {
					if ((int)usr_input == '\n')
						break;
					new_hobby.push_back(usr_input);
				}
				char* curr_hobby = new char[new_hobby.size()];
				for (int j = 0; j < new_hobby.size(); j++)
					curr_hobby[j] = new_hobby[j];
				curr_hobby[new_hobby.size()] = 0;
				new_hobby.clear();
				hobbies_lst.push_back(curr_hobby);
			}
			char** New_Hobbies_List = new char* [hobbies_lst.size()];
			for (int k = 0; k < hobbies_lst.size(); k++)
				New_Hobbies_List[k] = hobbies_lst[k];
			Client new_client(New_Id, New_Name, new_gender, new_age, New_Hobbies_List, new_hobbies_num);
			hobbies_lst.clear();
			this->database += new_client;
			user_choice = 0;
			break;
		}
		case 2: {
			new_string.clear();
			cout << "\tPlease enter client id to remove from database: " << endl;
			cout << "\tClient ID: > ";
			clean_buff();
			while (cin >> usr_input) {
				if ((int)usr_input == '\n')
					break;
				new_string.push_back(usr_input);
			}
			char* del_id_arr = new char[new_string.size() + 1];
			for (int i = 0; i < new_string.size(); i++)
				del_id_arr[i] = new_string[i];
			del_id_arr[new_string.size()] = '\0';
			String Del_Id(del_id_arr);
			for (int i = 0; i < database.get_clients_vec().size(); i++) {
				if (this->database.get_clients_vec()[i].get_Id() == Del_Id) {
					database -= database.get_clients_vec()[i];
					new_string.clear();
					user_choice = 0;
					break;
				}
				new_string.clear();
				cout << "\tThere is no client with the entered id: " << Del_Id << endl;
			}
			delete[] del_id_arr;
			user_choice = 0;
			break;
		}
		case 3: {
			cout << database;
			user_choice = 0;
			break;
		}
			  //
		case 4: {
			clean_buff();
			while (cin >> usr_input) {
			/////////////////////////// print acordingly
				if ((int)usr_input == '\n')
					break;
				new_string.push_back(usr_input);
				char* id_to_match = new char[new_string.size() + 1];
				for (int i = 0; i < new_string.size(); i++)
					id_to_match[i] = new_string[i];
				id_to_match[new_string.size()] = 0;
				const String Id_to_match(id_to_match);
				new_string.clear();
				database.PrintMatches(Id_to_match);
			}
			user_choice = 0;
			break;
		}
			  //
		case 5: {
			break;
		}
			  //
		default: {
			user_choice = 0;
			break;
		}
		}
	}
}

void Menu::clean_buff() {
	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}