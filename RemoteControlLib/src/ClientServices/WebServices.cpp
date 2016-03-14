/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ClientServices/WebServices.h"

namespace ElteRemoteControlLib {
namespace NS_ClientServices {

string* WebServices::generateSecurityKeys() {
	return nullptr;
}

string WebServices::registerUser(string username, string password) {
	return "";
}

string WebServices::unregisterUser() {
	return "";
}

string WebServices::login(string username, string password, uint16 port) {
	return "";
}

string WebServices::refreshStatus() {
	return "";
}

string WebServices::logout() {
	return "";
}

string WebServices::getUser() {
	return "";
}

string WebServices::getContacts() {
	return "";
}

string WebServices::findContacts(string search) {
	return "";
}

string WebServices::addContact(string username) {
	return "";
}

string WebServices::acceptContact(string username) {
	return "";
}

string WebServices::blockContact(string username) {
	return "";
}

string WebServices::getConnectionData(string username) {
	return "";
}

}
}
