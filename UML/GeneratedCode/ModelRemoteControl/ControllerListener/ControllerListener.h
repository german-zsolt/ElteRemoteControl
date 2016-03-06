/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTROLLERLISTENER_H
#define _CONTROLLERLISTENER_H

class ControllerListener {
public: 
    
    /**
     * @param sender
     */
    void ControllerListener(ControllerSender sender);
    
    virtual list<ControllerState> getActualState() = 0;
protected: 
    ControllerSender sender;
    list<ControllerState> actualState;
};

#endif //_CONTROLLERLISTENER_H