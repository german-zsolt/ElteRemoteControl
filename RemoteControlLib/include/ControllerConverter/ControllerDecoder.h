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
	static shared_ptr<ControllerState> getState(uint8* data);
};

}
}

#endif //_CONTROLLERDECODER_H
