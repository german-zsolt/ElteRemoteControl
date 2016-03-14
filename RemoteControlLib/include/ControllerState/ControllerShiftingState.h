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
	int16 shifting;
};

}
}

#endif //_CONTROLLERSHIFTINGSTATE_H
