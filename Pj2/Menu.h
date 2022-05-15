#include "MatchMakingAgency.h"
#include <iostream>
#include "string.h"
using namespace std;
class Menu
{
private:
	MatchMakingAgency database;
public:
	Menu() {}; //default Ctor
	~Menu() {}; //Dtor
	void MainMenu();
	void clean_buff();
};

