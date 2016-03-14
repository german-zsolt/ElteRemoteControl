/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONNECTIONDATA_H
#define _CONNECTIONDATA_H

#include <string>
#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ClientServices {

class ConnectionData {
public:
	string ip;
	string mac;
	uint16 port;
	string publicKey;
};

}
}

#endif //_CONNECTIONDATA_H
