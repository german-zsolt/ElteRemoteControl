/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _KEYBOARDBUTTONSTATE_H
#define _KEYBOARDBUTTONSTATE_H

#include "ControllerButtonState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class KeyboardButtonState: public ControllerButtonState {
public:
	static const uint8 CONTROLLER_TYPE = 1;
	uint8 getControllerType() const {
		return CONTROLLER_TYPE;
	}

	KeyboardButtonState(const uint8 controller, const bool pressed) :
			ControllerButtonState(controller, pressed) {
	}
};

}
}

#endif //_KEYBOARDBUTTONSTATE_H
