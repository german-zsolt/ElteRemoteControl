/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _KEYBOARDEXECUTOR_H
#define _KEYBOARDEXECUTOR_H

#include <memory>
#include "ControllerExecutor.h"
#include "ControllerState/KeyboardButtonState.h"
#include "ControllerState/KeyboardLockState.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerExecutor {

using namespace NS_ControllerState;

class KeyboardExecutor: public ControllerExecutor {
public:
	static void doChanges(shared_ptr<KeyboardButtonState> changes);
	static void doChanges(shared_ptr<KeyboardLockState> changes);
};

}
}

#endif //_KEYBOARDEXECUTOR_H
