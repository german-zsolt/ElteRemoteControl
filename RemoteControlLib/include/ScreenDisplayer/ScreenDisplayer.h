/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENDISPLAYER_H
#define _SCREENDISPLAYER_H

#include "General/GeneralTypes.h"
#include "ScreenScanner/Screen.h"
#include "ScreenScanner/ScreenDiff.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenDisplayer {

using namespace NS_ScreenScanner;

class ScreenDisplayer {
public:
	void addDiff(ScreenDiff diff);
private:
	uint8 monitorNumber;
	Screen actualImage;
};

}
}

#endif //_SCREENDISPLAYER_H
