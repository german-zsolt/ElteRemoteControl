/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENDIFF_H
#define _SCREENDIFF_H

#include "ScreenScanner/IRect.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class ScreenDiff: public IRect {
public:
	const uint8 shift;
	uint8* const diff;

	ScreenDiff(const uint16 positionX, const uint16 positionY,
			const uint16 sizeX, const uint16 sizeY, const uint8 shift) :
			IRect(positionX, positionY, sizeX, sizeY), shift(shift), diff(
					new uint8[sizeX * sizeY]) {
	}

	~ScreenDiff() {
		delete[] diff;
	}
};

}
}

#endif //_SCREENDIFF_H
