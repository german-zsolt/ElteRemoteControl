/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ControllerState/Controller2DPositionState.h"
#include "ControllerConverter/ControllerEncoder.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

using namespace NS_ControllerConverter;

uint8* Controller2DPositionState::getData() const {
	return ControllerEncoder::getData(*this);
}

}
}
