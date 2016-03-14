/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ScreenScanner/ScreenScanner.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

ScreenScanner::ScreenScanner(shared_ptr<ScreenSender> sender) {

}

shared_ptr<Screen> ScreenScanner::getActualImage() {
	return nullptr;
}

shared_ptr<ScreenDiff> ScreenScanner::getDiff() {
	return nullptr;
}

}
}
