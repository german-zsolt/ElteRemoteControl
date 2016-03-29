/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include "ScreenScanner/IRect.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

uint32 IRect::getIndex(const uint16 x, const uint16 y) const {
	return (y - this->positionY) * this->sizeX + x - this->positionX;
}

uint32 IRect::getSize() const {
	return this->sizeX * this->sizeY;
}

}
}
