/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENIMAGE_H
#define _SCREENIMAGE_H

#include "ScreenScanner/IRect.h"
#include "ScreenScanner/ScreenDiff.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class ScreenImage: public IRect {
public:
	uint32* const image;

	void addDiff(const ScreenDiff& diff);

	ScreenImage(const uint16 positionX, const uint16 positionY, const uint16 sizeX,
			const uint16 sizeY) :
			IRect(positionX, positionY, sizeX, sizeY), image(
					new uint32[sizeX * sizeY]) {
	}

	~ScreenImage() {
		delete[] image;
	}
};

}
}

#endif //_SCREENIMAGE_H
