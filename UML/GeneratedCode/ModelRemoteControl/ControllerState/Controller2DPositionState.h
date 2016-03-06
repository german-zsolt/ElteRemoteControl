/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTROLLER2DPOSITIONSTATE_H
#define _CONTROLLER2DPOSITIONSTATE_H

#include "ControllerState.h"


class Controller2DPositionState: public ControllerState {
public: 
    uint16[] position;
};

#endif //_CONTROLLER2DPOSITIONSTATE_H