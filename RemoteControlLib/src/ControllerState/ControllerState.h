/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTROLLERSTATE_H
#define _CONTROLLERSTATE_H

class ControllerState {
public: 
    uint8 controller;
    
    static uint8 getControllerType() = 0;
};

#endif //_CONTROLLERSTATE_H