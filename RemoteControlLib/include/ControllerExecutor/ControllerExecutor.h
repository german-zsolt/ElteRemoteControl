/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLEREXECUTOR_H
#define _CONTROLLEREXECUTOR_H

#include "General/GeneralTypes.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerExecutor {

class ControllerExecutor {
public:
	static void doChange(uint8* data);
};

}
}

#endif //_CONTROLLEREXECUTOR_H
