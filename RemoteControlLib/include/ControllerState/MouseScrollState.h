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
public:
	uint8 getControllerType() const;

	MouseScrollState(const uint8 controller, const int16 shifting) :
		ControllerShiftingState(controller, shifting) {
	}
};

}
}

#endif //_MOUSESCROLLSTATE_H
