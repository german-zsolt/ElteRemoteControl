/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENSCANNER_H
#define _SCREENSCANNER_H

#include "General/GeneralTypes.h"
#include "IScreenScanner.h"
#include "ScreenSender/ScreenSender.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

using namespace NS_ScreenSender;

class ScreenScanner {
public:
	ScreenScanner(shared_ptr<ScreenSender> sender);
	shared_ptr<Screen> getActualImage();
	shared_ptr<ScreenDiff> getDiff();
private:
	shared_ptr<ScreenSender> sender;
	uint8 monitorNumber;
	shared_ptr<Screen> remoteImage;
};

}
}

#endif //_SCREENSCANNER_H
