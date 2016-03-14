/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _SCREENSENDER_H
#define _SCREENSENDER_H

#include <forward_list>
#include "General/GeneralTypes.h"
#include "DataCommunication/DataSender.h"
#include "ScreenScanner/IScreenScanner.h"

namespace ElteRemoteControlLib {
namespace NS_ScreenSender {

using namespace NS_DataCommunication;
using namespace NS_ScreenScanner;

class ScreenSender {
public:
	ScreenSender(shared_ptr<DataSender> dataSender);
	void addScreen(shared_ptr<IScreenScanner> screen);
	void removeScreen(shared_ptr<IScreenScanner> screen);
private:
	forward_list<shared_ptr<IScreenScanner>> screens;
	shared_ptr<DataSender> dataSender;
	uint8 sentDataCount;
	uint8 receivedDataCount;
};

}
}

#endif //_SCREENSENDER_H
