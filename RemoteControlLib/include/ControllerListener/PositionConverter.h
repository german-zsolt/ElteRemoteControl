/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _POSITIONCONVERTER_H
#define _POSITIONCONVERTER_H

#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerListener {

class PositionConverter {
public:
	int16 offsetOriginal[2];
	int16 offsetTarget[2];
	uint16 sizeOriginal[2];
	uint16 sizeTarget[2];

	int16* getPositionTarget(int16 positionOriginal[2]);
};

}
}

#endif //_POSITIONCONVERTER_H
