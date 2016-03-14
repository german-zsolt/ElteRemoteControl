/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTACTDATA_H
#define _CONTACTDATA_H

#include <string>
#include <time.h>
#include "ConnectionData.h"

namespace ElteRemoteControlLib {
namespace NS_ClientServices {

class ContactData {
public:
	string username;
	time_t lastActive;
	ConnectionData connectionData;
};

}
}

#endif //_CONTACTDATA_H
