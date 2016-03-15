/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERDECODER_H
#define _CONTROLLERDECODER_H

#include <memory>
#include "ControllerState/ControllerState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerConverter {

using namespace NS_ControllerState;

class ControllerDecoder {
public:
	static unique_ptr<ControllerState> getState(const uint8* const data);

private:
	static int16 getSignedValue(const uint16& data);
	static uint16 getValue(const uint8& higherValue, const uint8& lowerValue);
};

}
}

#endif //_CONTROLLERDECODER_H
