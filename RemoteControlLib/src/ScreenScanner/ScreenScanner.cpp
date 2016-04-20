/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ScreenScanner/ScreenScanner.h"
#include <iostream>
#include <X11/Xutil.h>
#include "ScreenScanner/ColorConverter.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

/* TODO: later
 ScreenScanner::ScreenScanner(shared_ptr<ScreenSender> sender) {

 }
 */

unique_ptr<ScreenImage> ScreenScanner::getActualImage() {
	XWindowAttributes gwa;
	XGetWindowAttributes(display, root, &gwa);
	const int posX = gwa.x;
	const int posY = gwa.y;
	const int width = gwa.width;
	const int height = gwa.height;

	XImage *image = XGetImage(display, root, posX, posY, width, height,
			AllPlanes, ZPixmap);

	unique_ptr<ScreenImage> screen_ptr(
			new ScreenImage(posX, posY, width, height));
	uint32* const screenImage = screen_ptr->image;
	uint32 imageIndex = -1;
	for (int y = posY; y < height; ++y) {
		for (int x = posX; x < width; ++x) {
			screenImage[++imageIndex] = ColorConverter::toValue(
					XGetPixel(image, x, y));
		}
	}

	XDestroyImage(image);

	return screen_ptr;
}

unique_ptr<ScreenDiff> ScreenScanner::getDiff() {
	return nullptr;
}

}
}
