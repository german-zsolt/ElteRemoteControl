/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERSTATE_H
#define _CONTROLLERSTATE_H

#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class ControllerState {
public:
	uint8 controller;

	virtual uint8 getControllerType() = 0;
	virtual ~ControllerState();
};

}
}

#endif //_CONTROLLERSTATE_H
