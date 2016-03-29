/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENSCANNER_TEST_H
#define _SCREENSCANNER_TEST_H

#include <cxxtest/TestSuite.h>
#include "ScreenScanner/ColorConverter.h"
#include "ScreenScanner/Screen.h"
#include "ScreenScanner/ScreenDiff.h"
#include "boost/date_time/posix_time/posix_time_types.hpp" //no i/o just types

using namespace boost::posix_time;
using namespace ElteRemoteControlLib;
using namespace ElteRemoteControlLib::NS_ScreenScanner;

class ColorConverterTest: public CxxTest::TestSuite {
public:
	void testColorConverter() {
		ptime time_start(microsec_clock::local_time());

#ifdef TEST_ALL_VALUES
		for (uint16 red = 0; red < 256; ++red) {
			for (uint16 green = 0; green < 256; ++green) {
				for (uint16 blue = 0; blue < 256; ++blue) {
					assertColor(red, green, blue);
				}
			}
		}
#else
		assertColor(0, 0, 0);
		assertColor(128, 128, 128);
		assertColor(255, 255, 255);
		assertColor(1, 156, 234);
		assertColor(234, 156, 1);
#endif

		ptime time_end(microsec_clock::local_time());
		time_duration duration(time_end - time_start);
		TS_ASSERT_LESS_THAN(duration.total_milliseconds(), 5000);
	}
	void testScreenLowBytes() {
		Screen image(2, 14, 7, 4);
		ScreenDiff diff(4, 15, 3, 2, 0);
		const uint32 expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 101, 102, 103,
				13, 14, 15, 16, 104, 105, 106, 20, 21, 22, 23, 24, 25, 26, 27,
				28 };
		assertScreen(image, diff, 1, 101, expected);
	}
	void testScreenHighBytes() {
		Screen image(2, 14, 7, 4);
		ScreenDiff diff(4, 15, 3, 2, 8);
		const uint32 expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0x10A, 0x20B,
				0x30C, 13, 14, 15, 16, 0x411, 0x512, 0x613, 20, 21, 22, 23, 24,
				25, 26, 27, 28 };
		assertScreen(image, diff, 1, 1, expected);
	}
private:
	uint8 colorBuffer[3] = { 0, 0, 0 };
	template<typename T> void assertArrays(const T* const a1, const T* const a2,
			const uint32 size) {
		for (uint32 i = 0; i < size; ++i) {
			TS_ASSERT_EQUALS(a1[i], a2[i]);
		}
	}
	void assertColor(const uint8 red, const uint8 green, const uint8 blue) {
		uint32 value = ColorConverter::toValue(red, green, blue);

		// Assert equals when deconverted
		ColorConverter::toColor(value, colorBuffer, 0);
		TS_ASSERT_EQUALS(colorBuffer[0], red);
		TS_ASSERT_EQUALS(colorBuffer[1], green);
		TS_ASSERT_EQUALS(colorBuffer[2], blue);

		// Assert bigger values
		if (red < 255) {
			TS_ASSERT_LESS_THAN(value,
					ColorConverter::toValue(red + 1, green, blue));
		}
		if (green < 255) {
			TS_ASSERT_LESS_THAN(value,
					ColorConverter::toValue(red, green + 1, blue));
		}
		if (blue < 255) {
			TS_ASSERT_LESS_THAN(value,
					ColorConverter::toValue(red, green, blue + 1));
		}
	}
	void assertScreen(Screen& image, const ScreenDiff& diff,
			const uint32 startImageValue, const uint32 startDiffValue,
			const uint32* expected) {
		const uint32 imageSize = image.getSize();
		const uint32 diffSize = diff.getSize();
		for (uint32 i = 0, v = startImageValue; i < imageSize; ++i, ++v) {
			image.image[i] = v;
		}
		for (uint32 i = 0, v = startDiffValue; i < diffSize; ++i, ++v) {
			diff.diff[i] = v;
		}
		image.addDiff(diff);
		assertArrays(image.image, expected, image.getSize());
	}
};

#endif //_SCREENSCANNER_TEST_H
