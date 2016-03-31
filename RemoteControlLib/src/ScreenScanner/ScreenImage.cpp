/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#include <ScreenScanner/ScreenImage.h>
#include <algorithm>

namespace ElteRemoteControlLib {
namespace NS_ScreenScanner {

void ScreenImage::addDiff(const ScreenDiff& diff) {
	const uint16 startX = max(this->positionX, diff.positionX);
	const uint16 startY = max(this->positionY, diff.positionY);
	const uint16 endX = min(this->positionX + this->sizeX,
			diff.positionX + diff.sizeX);
	const uint16 endY = min(this->positionY + this->sizeY,
			diff.positionY + diff.sizeY);

	if (endX < startX || endY < startY) {
		return;
	}

	const uint32 bitmask = ~(0xFF << diff.shift);
	for (uint16 y = startY; y < endY; ++y) {
		uint32 diffIndex = diff.getIndex(startX, y);
		uint32 imageIndex = this->getIndex(startX, y);
		for (uint16 x = startX; x < endX; ++x) {
			this->image[imageIndex] = (this->image[imageIndex] & bitmask)
					| (diff.diff[diffIndex] << diff.shift);
			++diffIndex;
			++imageIndex;
		}
	}
}

}
}
