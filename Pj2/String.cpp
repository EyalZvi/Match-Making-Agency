#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

//-----------------------------------------------------------------------------------------------------------------//
void String::set_by_case(int start_index, int finish_index,const char* temp)
{
	// Helper func - insert ONLY the needed characters from temp char* by setting start and finish index (save in between)
	int j;
	for (j = 0 ; j < finish_index - start_index; j++) {
		this->str[j] = temp[j + start_index];
	}
	this->str[j] = '\0';
}


String::String()
{
	this->str = new char;
	str[0] = '\0';

}

String::String(char* string)
{
	// Ctor - Not default: we delete the unwanted spaces in the temp variable and then (with the helper) get the wanted string
	char* temp= new char[strlen(string)+1];
	int i = 0;
	int tmp_indx = 0;
	while (string[i] != '\0') {
		if (string[i] == ' ' && string[i + 1] == ' ') {  
			i++;
			continue;
		}													// Delete duplication of spaces, insert to temp 
		temp[tmp_indx] = string[i];
		i++;
		tmp_indx++;
	}

	temp[tmp_indx] = '\0';

	if (temp[0] == ' ') {
		if (temp[tmp_indx - 1] == ' ') {
			this->str = new char[tmp_indx -1];				// Send to helper Case 1 - Unwanted Space in start and finish
			set_by_case(1, tmp_indx - 1, temp);				// Use new accordingly 
		}
		else {
			this->str = new char[tmp_indx];					// Send to helper Case 2 - Unwanted Space only
			set_by_case(1, tmp_indx, temp);					// Use new accordingly 
		}
	}
	else {
		if (temp[tmp_indx - 1] == ' ') {					// Send to helper Case 3 - Unwanted Space finish only
			this->str = new char[tmp_indx];					// Use new accordingly 
			set_by_case(0, tmp_indx -1, temp);
		}
		else {
			this->str = new char[tmp_indx+1];				// Send to helper Case 4 - No Unwanted Space
			set_by_case(0, tmp_indx, temp);					// Use new accordingly 
		}
	}
	delete[] temp;											// Delete the temp variable (we do not need it anymore)
}

//-----------------------------------------------------------------------------------------------------------------//

String::String(const String& str_to_cpy)
{
	//Copy Ctor
	this->str = new char[strlen(str_to_cpy.str)+1];			// Use new for deep copy
	int i = 0;
	while (str_to_cpy.str[i] != '\0') {
		this->str[i] = str_to_cpy.str[i];					// Copy all characters from str_to_cpy
		i++;
	}
	this->str[i] = '\0';
}

//-----------------------------------------------------------------------------------------------------------------//

void String::operator=(const String& ob2)
{	
	//Overload '='  Operator 
	this->str = new char[strlen(ob2.str)+1];
	int i = 0;												// Use new for deep copy
	while (ob2.str[i] != '\0') {
		this->str[i] = ob2.str[i];							// Copy all characters from ob2
		i++;
	}
	this->str[i] = '\0';
}

//-----------------------------------------------------------------------------------------------------------------//

bool String::operator==(const String& ob2) const
{
	//Overload '=='  Operator 
	if (strlen(this->str) != strlen(ob2.str))
		return false;
															// Check if all chars in char* are the same return boolean variable accordingly
	int i = 0;												// ( We check size first to same time and cycles)
	while (ob2.str[i] != '\0') {
		if(this->str[i] != ob2.str[i])
			return false;
		i++;
	}
	return true;
}

//-----------------------------------------------------------------------------------------------------------------//

ostream& operator<<(ostream& out, const String& string)
{
	//Overload '<<' Cout
	out << string.str;
	return out;					// return the str char* variable to print 
}	

//-----------------------------------------------------------------------------------------------------------------//

String::~String()
{
	//Dtor
	delete[] str;	
};

//-----------------------------------------------------------------------------------------------------------------//