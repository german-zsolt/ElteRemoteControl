/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ControllerConverter/ControllerDecoder.h"
#include "ControllerState/KeyboardButtonState.h"
#include "ControllerState/KeyboardLockState.h"
#include "ControllerState/MouseButtonState.h"
#include "ControllerState/MousePositionState.h"
#include "ControllerState/MouseScrollState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerConverter {

unique_ptr<ControllerState> ControllerDecoder::getState(
		const uint8 data[]) {
	switch (data[0]) {
	case KeyboardButtonState::CONTROLLER_TYPE:
		return unique_ptr < KeyboardButtonState
				> (new KeyboardButtonState(data[1], num2bool(data[2])));
	case KeyboardLockState::CONTROLLER_TYPE:
		return unique_ptr < KeyboardLockState
				> (new KeyboardLockState(data[1], num2bool(data[2])));
	case MouseButtonState::CONTROLLER_TYPE:
		return unique_ptr < MouseButtonState
				> (new MouseButtonState(data[1], num2bool(data[2])));
	case MousePositionState::CONTROLLER_TYPE:
		return unique_ptr < MousePositionState
				> (new MousePositionState(data[1], getValue(data[2], data[3]),
						getValue(data[4], data[5])));
	case MouseScrollState::CONTROLLER_TYPE:
		return unique_ptr < MouseScrollState
				> (new MouseScrollState(data[1],
						getSignedValue(getValue(data[2], data[3]))));
	default:
		throw new invalid_argument("Invalid controller type: " + data[0]);
	}
}

bool ControllerDecoder::num2bool(const uint8 num) {
	return 0 == num ? false : true;
}
int16 ControllerDecoder::getSignedValue(const uint16 data) {
	return data - 0x100;
}
uint16 ControllerDecoder::getValue(const uint8 higherValue,
		const uint8 lowerValue) {
	return (higherValue << 8) | lowerValue;
}

}
}
