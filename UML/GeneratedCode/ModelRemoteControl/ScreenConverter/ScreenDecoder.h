/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _SCREENDECODER_H
#define _SCREENDECODER_H

class ScreenDecoder {
public: 
    
    /**
     * @param data
     */
    static ScreenDiff getDiff(uint8* data);
};

#endif //_SCREENDECODER_H