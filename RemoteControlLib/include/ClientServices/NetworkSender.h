/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _NETWORKSENDER_H
#define _NETWORKSENDER_H

#include <string>

namespace ElteRemoteControlLib {
namespace NS_ClientServices {

using namespace std;

class NetworkSender {
public:
	string requestRemoteAccess(string username);
	string requestRemoteHelp(string username);
	string acceptRemoteAccess(string username, int portTcp);
	string acceptRemoteHelp(string username, int portTcp);
private:
	int socket;
};

}
}

#endif //_NETWORKSENDER_H
