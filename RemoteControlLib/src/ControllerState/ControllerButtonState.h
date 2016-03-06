/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTROLLERBUTTONSTATE_H
#define _CONTROLLERBUTTONSTATE_H

#include "ControllerState.h"


class ControllerButtonState: public ControllerState {
public: 
    boolean pressed;
};

#endif //_CONTROLLERBUTTONSTATE_H