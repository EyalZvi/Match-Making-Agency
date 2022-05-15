#include <vector>
#include "Client.h"
using namespace std;

class MatchMakingAgency
{
private:
	//MatchMakingAgency variables (Private)
	int num_of_clients = 0;
	vector<Client> clients;

public:
	MatchMakingAgency() {};
	virtual ~MatchMakingAgency();
	void operator=(const MatchMakingAgency& ob2);
	void PrintMatches(const String &client_id);
	friend ostream& operator<<(ostream& out, MatchMakingAgency &database);
	void operator+=(Client& client);
	void operator-=(Client& client);
	vector<Client> get_clients_vec();
};
