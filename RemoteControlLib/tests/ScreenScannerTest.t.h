/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENSCANNER_TEST_H
#define _SCREENSCANNER_TEST_H

#include <cxxtest/TestSuite.h>
#include <cstdio>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/gil/extension/io/png_io.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "ScreenScanner/ColorConverter.h"
#include "ScreenScanner/ScreenDiff.h"
#include "ScreenScanner/ScreenImage.h"
#include "ScreenScanner/ScreenScanner.h"

using namespace boost::posix_time;
using namespace boost::gil;
using namespace ElteRemoteControlLib;
using namespace ElteRemoteControlLib::NS_ScreenScanner;

class ColorConverterTest: public CxxTest::TestSuite {
public:
	void testColorConverter() {
		ptime time_start(microsec_clock::local_time());

#ifdef TEST_ALL_VALUES
		for (uint32 color = 0; color < 0x1000000; ++color) {
			assertColor(color);
		}
#else
		// minimum, maximum, middle values
		assertColor(0x000000);
		assertColor(0x808080);
		assertColor(0xFFFFFF);
		// max bytes
		assertColor(0x0000FF);
		assertColor(0x00FF00);
		assertColor(0xFF0000);
		// increasing bytes, decreasing bytes
		assertColor(0x019CEA);
		assertColor(0xEA9C01);
		// same bytes
		assertColor(0x777777);
		// one bigger byte
		assertColor(0x777778);
		assertColor(0x777877);
		assertColor(0x787777);
		// one lower byte
		assertColor(0x777776);
		assertColor(0x777677);
		assertColor(0x767777);
#endif

		ptime time_end(microsec_clock::local_time());
		time_duration duration(time_end - time_start);
		TS_ASSERT_LESS_THAN(duration.total_milliseconds(), 5000);
	}
	void testScreenLowBytes() {
		ScreenImage image(2, 14, 7, 4);
		ScreenDiff diff(4, 15, 3, 2, 0);
		const uint32 expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 101, 102, 103,
				13, 14, 15, 16, 104, 105, 106, 20, 21, 22, 23, 24, 25, 26, 27,
				28 };
		assertScreen(image, diff, 1, 101, expected);
	}
	void testScreenHighBytes() {
		ScreenImage image(2, 14, 7, 4);
		ScreenDiff diff(4, 15, 3, 2, 8);
		const uint32 expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0x10A, 0x20B,
				0x30C, 13, 14, 15, 16, 0x411, 0x512, 0x613, 20, 21, 22, 23, 24,
				25, 26, 27, 28 };
		assertScreen(image, diff, 1, 1, expected);
	}
	void testScreenScannerScreenshot() {
		unique_ptr<ScreenScanner> screenScanner = unique_ptr<ScreenScanner>(
				new ScreenScanner(":0"));

		ptime time_start(microsec_clock::local_time());

		unique_ptr<ScreenImage> screen = screenScanner->getActualImage();

		ptime time_end(microsec_clock::local_time());
		time_duration duration(time_end - time_start);
		TS_ASSERT_LESS_THAN(duration.total_milliseconds(), 20);

		const uint32 size = screen->getSize();

		// Realistic size
		TS_ASSERT_LESS_THAN_EQUALS(640, screen->sizeX);
		TS_ASSERT_LESS_THAN_EQUALS(480, screen->sizeY);
		// At least has two colors
		TS_ASSERT(hasTwoDifferentColors(*screen));

		unique_ptr<uint32[]> colors(new uint32[size]);
		ColorConverter::toColors(screen->image, colors.get(), size);
		uint32 imageIndex = 0;
		uint8 redPixels[size], greenPixels[size], bluePixels[size];
		for (uint32 pixelIndex = 0; pixelIndex < size; ++pixelIndex) {
			redPixels[pixelIndex] = colors[imageIndex] >> 16 & 0xFF;
			greenPixels[pixelIndex] = colors[imageIndex] >> 8 & 0xFF;
			bluePixels[pixelIndex] = colors[imageIndex] & 0xFF;
			++imageIndex;
		}
		rgb8c_planar_view_t view = planar_rgb_view(screen->sizeX, screen->sizeY,
				redPixels, greenPixels, bluePixels, screen->sizeX);
		png_write_view("/tmp/test_screenshot.png", view);
	}
private:
	template<typename T> void assertArrays(const T* const a1, const T* const a2,
			const uint32 size) {
		for (uint32 i = 0; i < size; ++i) {
			TS_ASSERT_EQUALS(a1[i], a2[i]);
		}
	}
	void assertColor(const uint32 color) {
		const uint32 value = ColorConverter::toValue(color);
		const uint32 decodedColor = ColorConverter::toColor(value);
		TS_ASSERT_EQUALS(color, decodedColor);

		// Assert bigger values
		if ((color & 0xFF) < 0xFF) {
			assertColor(value, color + 1);
		}
		if ((color & 0xFF00) < 0xFF00) {
			assertColor(value, color + 0x100);
		}
		if (color < 0xFF0000) {
			assertColor(value, color + 0x10000);
		}
	}
	void assertColor(const uint value, const uint32 biggerRgb) {
		TS_ASSERT_LESS_THAN(value, ColorConverter::toValue(biggerRgb));
	}
	void assertScreen(ScreenImage& image, const ScreenDiff& diff,
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
	bool hasTwoDifferentColors(const ScreenImage& screen) {
		const uint32 firstColor = screen.image[0];
		for (uint32 i = 1; i < screen.getSize(); ++i) {
			if (firstColor != screen.image[i]) {
				return true;
			}
		}
		return false;
	}
};

#endif //_SCREENSCANNER_TEST_H
