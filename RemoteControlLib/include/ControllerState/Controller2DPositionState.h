/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLER2DPOSITIONSTATE_H
#define _CONTROLLER2DPOSITIONSTATE_H

#include "ControllerState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class Controller2DPositionState: public ControllerState {
public:
	const uint16 position[2];

	Controller2DPositionState(const uint8 controller, const uint16 position[2]) :
			ControllerState(controller), position { position[0], position[1] } {
	}
};

}
}

#endif //_CONTROLLER2DPOSITIONSTATE_H
