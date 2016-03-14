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
	virtual uint8 getControllerType();
};

}
}

#endif //_KEYBOARDBUTTONSTATE_H
