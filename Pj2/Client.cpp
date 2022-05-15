#include <iostream>
#include <cstring>
#include "Client.h"
//-----------------------------------------------------------------------------------------------------------------//
Client::Client()
{
	 //Default Ctor
	this->Age = 0;									// Default age 0
	this->Gender = '\0';							// Default gender '\0' (None)
	this->Hobbies_lst = 0;						// Default empty hobbies list
	this->Id = String();								// Default id NULL
	this->Name = String();						// Default name NULL
	this->Num_Of_Hobbies = 0;						// Default no hobbies
}
//-----------------------------------------------------------------------------------------------------------------//
Client::Client(String id, String name, char gender, double age, char** hobbies_lst, int num_of_hobbies)
{
	// Ctor 
	this->Id = String(id);
	this->Name = String(name);
	this->Gender = gender;							// Allocating new memory for variables
	this->Age = age;
	this->Num_Of_Hobbies = num_of_hobbies;
	this->Hobbies_lst = new char*  [num_of_hobbies];
	if (num_of_hobbies != 0 && hobbies_lst != NULL) {
		for (int i = 0; i < num_of_hobbies; i++) {
			this->Hobbies_lst[i] = new char[strlen(hobbies_lst[i]) + 1];
			strcpy(this->Hobbies_lst[i], hobbies_lst[i]);
		}
	}
	else
		this->Hobbies_lst = NULL;
}
//-----------------------------------------------------------------------------------------------------------------//

Client::Client(const Client& client_to_cpy)
{
	// Copy Ctor
	this->Id = String(client_to_cpy.Id);
	this->Name = String(client_to_cpy.Name);
	this->Gender = client_to_cpy.Gender;
	this->Age = client_to_cpy.Age;
	this->Num_Of_Hobbies = client_to_cpy.Num_Of_Hobbies;
	this->Hobbies_lst = new char* [client_to_cpy.Num_Of_Hobbies];
	if (client_to_cpy.Num_Of_Hobbies != 0 && client_to_cpy.Hobbies_lst != NULL) {
		for (int i = 0; i < client_to_cpy.Num_Of_Hobbies; i++) {
			this->Hobbies_lst[i] = new char[strlen(client_to_cpy.Hobbies_lst[i]) + 1];
			strcpy(this->Hobbies_lst[i], client_to_cpy.Hobbies_lst[i]);
		}
	}
	else
		this->Hobbies_lst = NULL;
}
//-----------------------------------------------------------------------------------------------------------------//

void Client::operator=(const Client& ob2)
{
	// Overload '=' Operator
	this->Id = String(ob2.Id);
	this->Name = String(ob2.Name);			
	this->Gender = ob2.Gender;				// making an new Client - allocating new memory for variables and copying ob2
	this->Age = ob2.Age;
	this->Num_Of_Hobbies = ob2.Num_Of_Hobbies;
	this->Hobbies_lst = ob2.Hobbies_lst;
}
//-----------------------------------------------------------------------------------------------------------------//

bool Client::operator==(const Client& ob2) const
{
	// Overload '==' Operator
	if (this->Gender == ob2.Gender)
		return false;
	if ((abs(this->Age - ob2.Age)) > 5)
		return false;										// Checking for a match by standarts of the match0-making compeny rules
	for (int i = 0; i < this->Num_Of_Hobbies; i++) {
		for (int j = 0; j < ob2.Num_Of_Hobbies; j++) {
			if (this->Hobbies_lst[i] == ob2.Hobbies_lst[j])
				return true;
		}
	}
	return false;
}
//-----------------------------------------------------------------------------------------------------------------//

Client::~Client()
{
	//Dtor
	for (int i = 0; i < this->Num_Of_Hobbies; i++)
			delete[] this->Hobbies_lst[i];						// Deleting all allocated memory
	delete[] Hobbies_lst;
}
//-----------------------------------------------------------------------------------------------------------------//





