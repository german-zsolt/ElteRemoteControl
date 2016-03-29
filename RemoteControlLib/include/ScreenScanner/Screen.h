/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREEN_H
#define _SCREEN_H

#include "ScreenScanner/IRect.h"
#include "ScreenScanner/ScreenDiff.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class Screen: public IRect {
public:
	uint32* const image;

	void addDiff(const ScreenDiff& diff);

	Screen(const uint16 positionX, const uint16 positionY, const uint16 sizeX,
			const uint16 sizeY) :
			IRect(positionX, positionY, sizeX, sizeY), image(
					new uint32[sizeX * sizeY]) {
	}

	~Screen() {
		delete[] image;
	}
};

}
}

#endif //_SCREEN_H
