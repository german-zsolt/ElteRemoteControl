/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _IRECT_H
#define _IRECT_H

#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

class IRect {
public:
	const uint16 positionX;
	const uint16 positionY;
	const uint16 sizeX;
	const uint16 sizeY;

	uint32 getIndex(const uint16 x, const uint16 y) const;
	uint32 getSize() const;

	IRect(const uint16 positionX, const uint16 positionY, const uint16 sizeX,
			const uint16 sizeY) :
			positionX(positionX), positionY(positionY), sizeX(sizeX), sizeY(
					sizeY) {
	}
};

}
}

#endif //_IRECT_H
