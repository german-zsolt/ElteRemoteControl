/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERENCODER_H
#define _CONTROLLERENCODER_H

#include <memory>
#include "General/GeneralTypes.h"
#include "ControllerState/ControllerState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerConverter {

using namespace NS_ControllerState;

class ControllerEncoder {
public:
	static uint8* getData(shared_ptr<ControllerState> state);
};

}
}

#endif //_CONTROLLERENCODER_H
