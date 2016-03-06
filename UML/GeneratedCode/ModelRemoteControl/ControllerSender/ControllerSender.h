/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTROLLERSENDER_H
#define _CONTROLLERSENDER_H

class ControllerSender {
public: 
    
    /**
     * @param dataSender
     */
    void ControllerSender(DataSender dataSender);
    
    /**
     * @param listener
     */
    void addListener(ControllerListener listener);
    
    /**
     * @param change
     */
    void addChange(ControllerState change);
private: 
    forward_list<ControllerListener> listeners;
    queue<ControllerState> stateChanges;
    DataSender dataSender;
};

#endif //_CONTROLLERSENDER_H