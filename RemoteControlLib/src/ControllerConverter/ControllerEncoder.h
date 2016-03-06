/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTROLLERENCODER_H
#define _CONTROLLERENCODER_H

class ControllerEncoder {
public: 
    
    /**
     * @param state
     */
    static uint8* getData(ControllerState state);
};

#endif //_CONTROLLERENCODER_H