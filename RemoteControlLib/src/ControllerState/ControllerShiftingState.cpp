/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ControllerState/ControllerShiftingState.h"
#include "ControllerConverter/ControllerEncoder.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerState {

using namespace NS_ControllerConverter;

unique_ptr<uint8[]> ControllerShiftingState::getData() const {
	return ControllerEncoder::getData(*this);
}

}
}
