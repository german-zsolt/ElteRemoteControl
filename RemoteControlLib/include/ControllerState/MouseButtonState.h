/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _MOUSEBUTTONSTATE_H
#define _MOUSEBUTTONSTATE_H

#include "ControllerButtonState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class MouseButtonState: public ControllerButtonState {
public:
	static const uint8 CONTROLLER_TYPE = 3;
	uint8 getControllerType() const {
		return CONTROLLER_TYPE;
	}

	MouseButtonState(const uint8 controller, const bool pressed) :
			ControllerButtonState(controller, pressed) {
	}
};

}
}

#endif //_MOUSEBUTTONSTATE_H
