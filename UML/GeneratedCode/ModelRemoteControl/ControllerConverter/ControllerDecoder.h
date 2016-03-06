/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTROLLERDECODER_H
#define _CONTROLLERDECODER_H

class ControllerDecoder {
public: 
    
    /**
     * @param data
     */
    static ControllerState getState(uint8* data);
};

#endif //_CONTROLLERDECODER_H