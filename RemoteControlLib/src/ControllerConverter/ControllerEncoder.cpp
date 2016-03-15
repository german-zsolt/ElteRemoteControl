/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ControllerConverter/ControllerEncoder.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerConverter {

uint8* ControllerEncoder::getData(const Controller2DPositionState& state) {
	return new uint8[6] { state.getControllerType(), state.controller,
			getHigherValue(state.positionX), getLowerValue(state.positionX),
			getHigherValue(state.positionY), getLowerValue(state.positionY) };
}
uint8* ControllerEncoder::getData(const ControllerButtonState& state) {
	return new uint8[3] { state.getControllerType(), state.controller,
			state.pressed ? (uint8) 1 : (uint8) 0 };
}
uint8* ControllerEncoder::getData(const ControllerShiftingState& state) {
	const uint16 unsignedShifting = getUnsignedValue(state.shifting);
	return new uint8[4] { state.getControllerType(), state.controller,
			getHigherValue(unsignedShifting), getLowerValue(unsignedShifting) };
}

uint16 ControllerEncoder::getUnsignedValue(const int16& data) {
	return (uint16) (data + 0x100);
}
uint8 ControllerEncoder::getHigherValue(const uint16& data) {
	return (uint8) ((data >> 8) & 0xFF);
}
uint8 ControllerEncoder::getLowerValue(const uint16& data) {
	return (uint8) (data & 0xFF);
}

}
}
