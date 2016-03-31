/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _ISCREENSCANNER_H
#define _ISCREENSCANNER_H

#include <memory>
#include "ScreenDiff.h"
#include "ScreenScanner/ScreenImage.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class IScreenScanner {
public:
	virtual shared_ptr<ScreenImage> getActualImage() = 0;
	virtual shared_ptr<ScreenDiff> getDiff() = 0;
};

}
}

#endif //_ISCREENSCANNER_H
