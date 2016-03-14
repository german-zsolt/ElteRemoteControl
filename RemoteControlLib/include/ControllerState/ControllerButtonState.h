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
	bool pressed;
};

}
}

#endif //_CONTROLLERBUTTONSTATE_H
