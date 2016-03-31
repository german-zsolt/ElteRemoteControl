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
	Display* display = XOpenDisplay(displayName.c_str());
	Window root = DefaultRootWindow(display);
	XWindowAttributes gwa;
	XGetWindowAttributes(display, root, &gwa);
	const int width = gwa.width;
	const int height = gwa.height;

	XImage *image = XGetImage(display, root, 0, 0, width, height, AllPlanes,
	ZPixmap);

	unique_ptr<ScreenImage> screen_ptr(
			new ScreenImage(gwa.x, gwa.y, width, height));
	uint32* const screenImage = screen_ptr->image;
	uint32 imageIndex = -1;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			screenImage[++imageIndex] = ColorConverter::toValue(
					XGetPixel(image, x, y));
		}
	}

	XCloseDisplay(display);

	return screen_ptr;
}

unique_ptr<ScreenDiff> ScreenScanner::getDiff() {
	return nullptr;
}

}
}
