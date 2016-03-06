/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _SCREENDISPLAYER_H
#define _SCREENDISPLAYER_H

class ScreenDisplayer {
public: 
    
    /**
     * @param diff
     */
    void addDiff(ScreenDiff diff);
private: 
    void monitorNumber;
    Screen actualImage;
};

#endif //_SCREENDISPLAYER_H