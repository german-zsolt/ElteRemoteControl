/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENDIFF_H
#define _SCREENDIFF_H

#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class ScreenDiff {
public:
	uint16 position[2];
	uint16 size[2];
	uint8 shift;
	uint8* diff;
};

}
}

#endif //_SCREENDIFF_H
