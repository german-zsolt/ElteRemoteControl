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
	virtual uint8 getControllerType();
};

}
}

#endif //_MOUSEPOSITIONSTATE_H
