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
	virtual uint8 getControllerType();
};

}
}

#endif //_KEYBOARDLOCKSTATE_H
