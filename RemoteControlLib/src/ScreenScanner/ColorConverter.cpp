/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ScreenScanner/ColorConverter.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

uint32 ColorConverter::toValue(const uint8 colorRed, const uint8 colorGreen,
		const uint8 colorBlue) {
	uint32 value = 0;

	uint8 bitIndex = 1;
	uint32 bitShifting = 0;
	for (char i = 8; i > 0; --i) {
		value |= (colorBlue & bitIndex) << bitShifting;
		++bitShifting;
		value |= (colorGreen & bitIndex) << bitShifting;
		++bitShifting;
		value |= (colorRed & bitIndex) << bitShifting;
		bitIndex <<= 1;
		// Bit shifting not increased, because the bitIndex is increased
	}

	return value;
}

void ColorConverter::toColor(const uint32 value, uint8 color[],
		const uint32 offset) {
	uint8 colorRed = 0, colorGreen = 0, colorBlue = 0;

	uint32 bitIndex = 1;
	uint8 bitShifting = 0;
	for (int i = 8; i > 0; --i) {
		colorBlue |= (value & bitIndex) >> bitShifting;
		bitIndex <<= 1;
		++bitShifting;
		colorGreen |= (value & bitIndex) >> bitShifting;
		bitIndex <<= 1;
		++bitShifting;
		colorRed |= (value & bitIndex) >> bitShifting;
		bitIndex <<= 1;
		// Not increased the bit shifting, because in the next loop it should be higher bit
	}

	color[offset] = colorRed;
	color[offset + 1] = colorGreen;
	color[offset + 2] = colorBlue;
}

void ColorConverter::toColors(const uint32 values[], uint8 colors[],
		const uint32 size) {
	for (uint32 i = 0, offset = 0; i < size; ++i, offset += 3) {
		toColor(values[i], colors, offset);
	}
}

}
}
