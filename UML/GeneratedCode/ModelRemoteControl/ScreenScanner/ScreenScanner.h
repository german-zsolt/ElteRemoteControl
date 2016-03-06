/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _SCREENSCANNER_H
#define _SCREENSCANNER_H

class ScreenScanner {
public: 
    
    /**
     * @param sender
     */
    void ScreenSender(ScreenSender sender);
    
    Screen getActualImage();
    
    ScreenDiff getDiff();
private: 
    ScreenSender sender;
    uint8 monitorNumber;
    Screen remoteImage;
};

#endif //_SCREENSCANNER_H