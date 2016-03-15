/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _MOUSEPOSITIONSTATE_H
#define _MOUSEPOSITIONSTATE_H

#include "Controller2DPositionState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class MousePositionState: public Controller2DPositionState {
public:
	static const uint8 CONTROLLER_TYPE = 4;
	uint8 getControllerType() const {
		return CONTROLLER_TYPE;
	}

	MousePositionState(const uint8 controller, const uint16 positionX,
			const uint16 positionY) :
			Controller2DPositionState(controller, positionX, positionY) {
	}
};

}
}

#endif //_MOUSEPOSITIONSTATE_H
