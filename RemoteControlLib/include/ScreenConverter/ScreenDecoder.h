/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENDECODER_H
#define _SCREENDECODER_H

#include <memory>
#include "General/GeneralTypes.h"
#include "ScreenScanner/ScreenDiff.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenConverter {

using namespace NS_ScreenScanner;

class ScreenDecoder {
public:
	static shared_ptr<ScreenDiff> getDiff(uint8* data);
};

}
}

#endif //_SCREENDECODER_H
