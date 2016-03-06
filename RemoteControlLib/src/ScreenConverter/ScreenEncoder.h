/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _SCREENENCODER_H
#define _SCREENENCODER_H

class ScreenEncoder {
public: 
    
    /**
     * @param diff
     */
    static uint8* getData(ScreenDiff diff);
};

#endif //_SCREENENCODER_H