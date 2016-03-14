/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _MOUSEBUTTONSTATE_H
#define _MOUSEBUTTONSTATE_H

#include "ControllerButtonState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

class MouseButtonState: public ControllerButtonState {
	virtual uint8 getControllerType();
};

}
}

#endif //_MOUSEBUTTONSTATE_H
