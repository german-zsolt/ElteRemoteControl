/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _ISCREENSCANNER_H
#define _ISCREENSCANNER_H

#include <memory>
#include "Screen.h"
#include "ScreenDiff.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class IScreenScanner {
public:
	virtual shared_ptr<Screen> getActualImage() = 0;
	virtual shared_ptr<ScreenDiff> getDiff() = 0;
};

}
}

#endif //_ISCREENSCANNER_H
