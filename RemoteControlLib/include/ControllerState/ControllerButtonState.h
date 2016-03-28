/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERBUTTONSTATE_H
#define _CONTROLLERBUTTONSTATE_H

#include "ControllerState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class ControllerButtonState: public ControllerState {
public:
	const bool pressed;

	ControllerButtonState(const uint8 controller, const bool pressed) :
			ControllerState(controller), pressed(pressed) {
	}
	unique_ptr<uint8[]> getData() const;
};

}
}

#endif //_CONTROLLERBUTTONSTATE_H
