/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENSCANNER_H
#define _SCREENSCANNER_H

#include <X11/Xlib.h>
#include "General/GeneralTypes.h"
#include "ScreenScanner/IScreenScanner.h"
#include "ScreenSender/ScreenSender.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

using namespace NS_ScreenSender;

class ScreenScanner {
public:
	// TODO: later
	//ScreenScanner(shared_ptr<ScreenSender> sender);
	ScreenScanner(const string displayName) :
			displayName(displayName) {
	}

	unique_ptr<ScreenImage> getActualImage();
	unique_ptr<ScreenDiff> getDiff();
private:
	const string displayName;
	unique_ptr<ScreenSender> sender;
	unique_ptr<ScreenImage> remoteImage;
};

}
}

#endif //_SCREENSCANNER_H
