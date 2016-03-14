/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _WEBSERVICES_H
#define _WEBSERVICES_H

#include <map>
#include <memory>
#include <string>
#include "General/GeneralTypes.h"
#include "ContactData.h"

namespace ElteRemoteControlLib {
namespace NS_ClientServices {

class WebServices {
public:
	static string* generateSecurityKeys();
	string registerUser(string username, string password);
	string unregisterUser();
	string login(string username, string password, uint16 port);
	string refreshStatus();
	string logout();
	string getUser();
	string getContacts();
	string findContacts(string search);
	string addContact(string username);
	string acceptContact(string username);
	string blockContact(string username);
	string getConnectionData(string username);
private:
	int socket;
	string loggedInUser;
	string loggedInPassword;
	string privateKey;
	string publicKey;
	map<string, unique_ptr<ContactData>> contacts;
};

}
}

#endif //_WEBSERVICES_H
