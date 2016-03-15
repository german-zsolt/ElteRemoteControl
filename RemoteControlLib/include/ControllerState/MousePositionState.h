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
	uint8 getControllerType() const;

	MousePositionState(const uint8 controller, const uint16 position[2]) :
			Controller2DPositionState(controller, position) {
	}
};

}
}

#endif //_MOUSEPOSITIONSTATE_H
