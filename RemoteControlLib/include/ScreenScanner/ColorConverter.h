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
	static uint32 toValue(const uint32 rgbColor);
	static uint32 toColor(const uint32 value);
	static void toColors(const uint32 values[], uint32 rgbColors[],
			const uint32 size);
};

}
}

#endif //_COLORCONVERTER_H
