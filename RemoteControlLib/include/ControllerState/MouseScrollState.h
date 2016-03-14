/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _MOUSESCROLLSTATE_H
#define _MOUSESCROLLSTATE_H

#include "ControllerShiftingState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class MouseScrollState: public ControllerShiftingState {
	virtual uint8 getControllerType();
};

}
}

#endif //_MOUSESCROLLSTATE_H
