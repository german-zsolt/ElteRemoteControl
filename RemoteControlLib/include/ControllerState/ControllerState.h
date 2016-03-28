/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERSTATE_H
#define _CONTROLLERSTATE_H

#include <memory>
#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class ControllerState {
public:
	const uint8 controller;

	ControllerState(const uint8 controller) :
			controller(controller) {
	}

	virtual uint8 getControllerType() const = 0;
	virtual unique_ptr<uint8[]> getData() const = 0;
	virtual ~ControllerState() {
	}
};

}
}

#endif //_CONTROLLERSTATE_H
