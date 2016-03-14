/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _MOUSEEXECUTOR_H
#define _MOUSEEXECUTOR_H

#include <memory>
#include "ControllerExecutor.h"
#include "ControllerState/MouseButtonState.h"
#include "ControllerState/MousePositionState.h"
#include "ControllerState/MouseScrollState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerExecutor {

using namespace NS_ControllerState;

class MouseExecutor: public ControllerExecutor {
public:
	static void doChanges(shared_ptr<MouseButtonState> changes);
	static void doChanges(shared_ptr<MousePositionState> changes);
	static void doChanges(shared_ptr<MouseScrollState> changes);
};

}
}

#endif //_MOUSEEXECUTOR_H
