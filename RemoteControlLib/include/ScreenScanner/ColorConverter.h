/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _COLORCONVERTER_H
#define _COLORCONVERTER_H

#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class ColorConverter {
public:
	static uint32 toValue(uint8 color[3]);
	static uint8* toColor(uint32 value);
	static uint8* toColors(uint32* value, unsigned int size);
};

}
}

#endif //_COLORCONVERTER_H
