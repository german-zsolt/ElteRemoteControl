/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERENCODER_H
#define _CONTROLLERENCODER_H

#include <memory>
#include "ControllerState/Controller2DPositionState.h"
#include "ControllerState/ControllerButtonState.h"
#include "ControllerState/ControllerShiftingState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerConverter {

using namespace NS_ControllerState;

class ControllerEncoder {
public:
	static unique_ptr<uint8[]> getData(const Controller2DPositionState& state);
	static unique_ptr<uint8[]> getData(const ControllerButtonState& state);
	static unique_ptr<uint8[]> getData(const ControllerShiftingState& state);

private:
	static uint8 bool2num(const bool b);
	static uint16 getUnsignedValue(const int16 data);
	static uint8 getHigherValue(const uint16 data);
	static uint8 getLowerValue(const uint16 data);
};

}
}

#endif //_CONTROLLERENCODER_H
