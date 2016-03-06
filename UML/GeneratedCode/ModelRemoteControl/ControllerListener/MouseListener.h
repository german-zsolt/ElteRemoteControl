/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _MOUSELISTENER_H
#define _MOUSELISTENER_H

#include "ControllerListener.h"


class MouseListener: public ControllerListener {
public: 
    
    /**
     * @param converter
     */
    void MouseScanner(PositionConverter converter);
    
    /**
     * @param converter
     */
    void setPositionConverter(PositionConverter converter);
private: 
    PositionConverter positionConverter;
};

#endif //_MOUSELISTENER_H