/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _KEYBOARDLOCKSTATE_H
#define _KEYBOARDLOCKSTATE_H

#include "ControllerButtonState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class KeyboardLockState: public ControllerButtonState {
public:
	uint8 getControllerType() const;

	KeyboardLockState(const uint8 controller, const bool pressed) :
			ControllerButtonState(controller, pressed) {
	}
};

}
}

#endif //_KEYBOARDLOCKSTATE_H
