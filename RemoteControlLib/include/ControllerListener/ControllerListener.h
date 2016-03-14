/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERLISTENER_H
#define _CONTROLLERLISTENER_H

#include <memory>
#include "IControllerListener.h"
#include "ControllerSender/ControllerSender.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerListener {

using namespace NS_ControllerSender;

class ControllerListener: public IControllerListener {
public:
	ControllerListener(shared_ptr<ControllerSender> sender);
protected:
	shared_ptr<ControllerSender> sender;
	list<shared_ptr<ControllerState>> actualState;
};

}
}

#endif //_CONTROLLERLISTENER_H
