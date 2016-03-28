/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERSHIFTINGSTATE_H
#define _CONTROLLERSHIFTINGSTATE_H

#include "ControllerState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class ControllerShiftingState: public ControllerState {
public:
	const int16 shifting;

	ControllerShiftingState(const uint8 controller, const int16 shifting) :
			ControllerState(controller), shifting(shifting) {
	}
	unique_ptr<uint8[]> getData() const;
};

}
}

#endif //_CONTROLLERSHIFTINGSTATE_H
