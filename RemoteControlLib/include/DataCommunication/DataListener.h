/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _DATALISTENER_H
#define _DATALISTENER_H

#include <memory>
#include <string>
#include <ScreenDisplayer/ScreenDisplayer.h>

namespace ElteRemoteControlLib {
namespace NS_DataCommunication {

using namespace NS_ScreenDisplayer;

class DataListener {
public:
	void initConnection(string protocol, int port);
private:
	int socket;
	string privateKey;
	string publicKey;
	shared_ptr<ScreenDisplayer> screenDisplayer;
};

}
}

#endif //_DATALISTENER_H
