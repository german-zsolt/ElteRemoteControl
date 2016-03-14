/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _ICONTROLLERLISTENER_H
#define _ICONTROLLERLISTENER_H

#include <list>
#include "ControllerState/ControllerState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerListener {

using namespace NS_ControllerState;

class IControllerListener {
public:
	virtual list<shared_ptr<ControllerState>> getActualState() = 0;
	virtual ~IControllerListener() = 0;
};

}
}

#endif //_ICONTROLLERLISTENER_H
