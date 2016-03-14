/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERSENDER_H
#define _CONTROLLERSENDER_H

#include <forward_list>
#include <memory>
#include <queue>
#include "ControllerListener/IControllerListener.h"
#include "DataCommunication/DataSender.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerSender {

using namespace NS_DataCommunication;
using namespace NS_ControllerListener;

class ControllerSender {
public:
	ControllerSender(shared_ptr<DataSender> dataSender);
	void addListener(shared_ptr<IControllerListener> listener);
	void addChange(shared_ptr<ControllerState> change);
private:
	forward_list<shared_ptr<IControllerListener>> listeners;
	queue<shared_ptr<ControllerState>> stateChanges;
	shared_ptr<DataSender> dataSender;
};

}
}

#endif //_CONTROLLERSENDER_H
