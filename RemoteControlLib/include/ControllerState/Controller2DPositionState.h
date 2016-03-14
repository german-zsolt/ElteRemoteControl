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
	uint16 position[2];
};

}
}

#endif //_CONTROLLER2DPOSITIONSTATE_H
