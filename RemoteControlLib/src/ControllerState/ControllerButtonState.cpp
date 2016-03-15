/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ControllerState/ControllerButtonState.h"
#include "ControllerConverter/ControllerEncoder.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

using namespace NS_ControllerConverter;

uint8* ControllerButtonState::getData() const {
	return ControllerEncoder::getData(*this);
}

}
}
