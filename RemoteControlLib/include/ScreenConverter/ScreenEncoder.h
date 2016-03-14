/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENENCODER_H
#define _SCREENENCODER_H

#include <memory>
#include "General/GeneralTypes.h"
#include "ScreenScanner/ScreenDiff.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenConverter {

using namespace NS_ScreenScanner;

class ScreenEncoder {
public:
	static uint8* getData(shared_ptr<ScreenDiff> diff);
};

}
}

#endif //_SCREENENCODER_H
