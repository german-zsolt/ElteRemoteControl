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
	static uint32 toValue(const uint8 colorRed, const uint8 colorGreen,
			const uint8 colorBlue);
	static void toColor(const uint32 value, uint8 color[], const uint32 offset);
	static void toColors(const uint32 values[], uint8 colors[], const uint32 size);
};

}
}

#endif //_COLORCONVERTER_H
