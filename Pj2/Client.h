#include <iostream>
#include <cstring>
#include "String.h"
#pragma once
class Client
{
private:
	String Id, Name;			// All Client variables (Private)
	char Gender;
	double Age;
	int Num_Of_Hobbies;
	char** Hobbies_lst;

public:							// All Client Methods (Public)
	Client();
	Client(String id, String name, char gender, double age, char** hobbies_lst, int num_of_hobbies);
	Client(const Client& client_to_cpy);
	virtual ~Client();
	void operator=(const Client& ob2);
	bool operator==(const Client& ob2) const;
	const String get_Id() { return this->Id; };		// Getters 
	const String get_Name() { return this->Name; };
	const char get_Gender() { return this->Gender; };
	const double get_Age() { return this->Age; };
	const int get_Num_Of_Hobbies() { return this->Num_Of_Hobbies; };
	char** get_Hobbies_lst() const { return this->Hobbies_lst; };
};

