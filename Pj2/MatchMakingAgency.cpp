#include "MatchMakingAgency.h"
#include <iostream>
using namespace std;

void MatchMakingAgency::operator=(const MatchMakingAgency& ob2)
{
	this->num_of_clients = ob2.num_of_clients;
	this->clients = ob2.clients;
}

void MatchMakingAgency::PrintMatches(const String &client_id)
{
	Client to_match_for;
	bool flag = false;
	for (int i = 0; i < this->num_of_clients; i++) {
		if (this->clients[i].get_Id() == client_id) //////////////////////////////////////
			to_match_for = this->clients[i];
		flag = true;
	}
	if (flag == false) {
		cout << "\tNo client with id : " << client_id << " found in the database" << endl;
		return;
	}

	cout << "\tClient " << to_match_for.get_Name() << " id: " << to_match_for.get_Id() << " has matched with: " << endl << endl;
	char** match_hob = new char*;

	for (int j = 0; j < this->num_of_clients; j++) {
		if ((this->clients[j] == to_match_for) && !(this->clients[j].get_Id() == to_match_for.get_Id())) {
			cout << "\t" << clients[j].get_Name() << " Gender: " << clients[j].get_Gender() << " Id: " << clients[j].get_Id() << " Age: " << clients[j].get_Age() << " years old." << endl;
			cout << "\t" << clients[j].get_Num_Of_Hobbies() << " Hobbies registerd including" << endl;
			match_hob = clients[j].get_Hobbies_lst();
			for (int k = 0; k < clients[j].get_Num_Of_Hobbies()-1; k++) {
				cout<< " " << match_hob[k];
			}
			cout<< ". " << endl << endl;
		}
	}

}

void MatchMakingAgency::operator+=(Client& client)
{
	if (this->num_of_clients != 0) {
		for (int i = 0; i < this->num_of_clients - 1; i++) {
			if (this->clients[i].get_Id() == client.get_Id())
				return;
		}
	}
	this->num_of_clients +=1;
	this->clients.push_back(client);
}

void MatchMakingAgency::operator-=(Client& client)
{
	for (int i = 0; i < this->num_of_clients; i++) {
		if (this->clients[i].get_Id() == client.get_Id()) {
			this->clients.erase(clients.begin() + i);
			this->num_of_clients -= 1;
			break;
		}
	}

}

ostream& operator<<(ostream& out, MatchMakingAgency &database)
{
	char** match_hob;
	out << "\t==========================================================" << endl;
	for (int j = 0; j < int(database.clients.size()); j++) {
		out << "\tClient #" << j + 1 << " Details:" << endl;
		out << "\tName:" << database.clients[j].get_Name() << endl;
		out << "\tId: " << database.clients[j].get_Id() << endl;
		out << "\tGender: " << database.clients[j].get_Gender() << endl;
		out << "\tAge: " << database.clients[j].get_Age() << " years old." << endl;
		out << "\tHobbies registered including: " << database.clients[j].get_Num_Of_Hobbies();
		match_hob = database.clients[j].get_Hobbies_lst();
		for (int k = 0; k < database.clients[j].get_Num_Of_Hobbies()-1; k++) {
			out << " " << match_hob[k];
		}
		out << ". " << endl << endl;
	}
	out << "\t==========================================================" << endl;
	return out;
}


vector<Client> MatchMakingAgency::get_clients_vec()
{
	return this->clients;
}


MatchMakingAgency::~MatchMakingAgency()
{
	// Distructor
	this->num_of_clients = 0;
	this->clients.clear();
}
