#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class String
{
private:
	char* str;																 // str - char* type, Class String variable
	void set_by_case(int start_index, int finish_index, const char* temp);	 // Helper method (Private)

public:
	String();	// Default string as space		
	String(char* string);
	String(const String& str_to_cpy);										// All String methods (Public)
	void operator=(const String& ob2);
	bool operator==(const String& ob2) const;
	friend ostream& operator<<(ostream& out, const String& string);
	virtual ~String();
};

