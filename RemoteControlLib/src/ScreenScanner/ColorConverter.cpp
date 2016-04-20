/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ScreenScanner/ColorConverter.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

uint32 ColorConverter::toValue(const uint32 rgbColor) {
	uint32 remainingColor = rgbColor, value = 0;
	for (uint8 j = 0; j < 3; ++j) {
		for (uint8 i = j; i < 24; i += 3) {
			value |= (remainingColor & 1) << i;
			remainingColor >>= 1;
		}
	}
	return value;
}

uint32 ColorConverter::toColor(const uint32 value) {
	uint32 remainingValue = value, color = 0;
	for (uint8 j = 0; j < 8; ++j) {
		for (uint8 i = j; i < 24; i += 8) {
			color |= (remainingValue & 1) << i;
			remainingValue >>= 1;
		}
	}
	return color;
}

void ColorConverter::toColors(const uint32 values[], uint32 rgbColors[],
		const uint32 size) {
	for (uint32 i = 0; i < size; ++i) {
		rgbColors[i] = toColor(values[i]);
	}
}

}
}
