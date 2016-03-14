/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _DATASENDER_H
#define _DATASENDER_H

#include <string>
#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_DataCommunication {

class DataSender {
public:
	void initConnection(string protocol, string ip, string mac, int port);
	void sendData(uint8* data, uint32 size);
	void closeConnection();
private:
	int socket;
	string privateKey;
	string publicKey;
};

}
}

#endif //_DATASENDER_H
