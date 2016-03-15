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
	const uint16 positionX;
	const uint16 positionY;

	Controller2DPositionState(const uint8 controller, const uint16 positionX,
			const uint16 positionY) :
			ControllerState(controller), positionX(positionX), positionY(
					positionY) {
	}
	uint8* getData() const;
};

}
}

#endif //_CONTROLLER2DPOSITIONSTATE_H
