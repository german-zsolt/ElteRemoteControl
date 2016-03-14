/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _MOUSELISTENER_H
#define _MOUSELISTENER_H

#include "ControllerListener.h"
#include "PositionConverter.h"

namespace ElteRemoteControlLib {
namespace NS_ControllerListener {

class MouseListener: public ControllerListener {
public:
	void MouseScanner(unique_ptr<PositionConverter> converter);
	void setPositionConverter(unique_ptr<PositionConverter> converter);
private:
	unique_ptr<PositionConverter> positionConverter;
};

}
}

#endif //_MOUSELISTENER_H
