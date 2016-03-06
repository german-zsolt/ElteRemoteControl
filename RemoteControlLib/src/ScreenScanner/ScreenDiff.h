/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _SCREENDIFF_H
#define _SCREENDIFF_H

class ScreenDiff {
public: 
    uint16[] position;
    uint16[] size;
    uint8 shift;
    uint8* diff;
};

#endif //_SCREENDIFF_H