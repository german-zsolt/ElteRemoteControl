/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREEN_H
#define _SCREEN_H

#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class Screen {
public:
	uint16 position[2];
	uint16 size[2];
	uint32* image;
};

}
}

#endif //_SCREEN_H
