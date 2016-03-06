/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _SCREENSENDER_H
#define _SCREENSENDER_H

class ScreenSender {
public: 
    
    /**
     * @param dataSender
     */
    void ScreenSender(DataSender dataSender);
    
    /**
     * @param screen
     */
    void addScreen(ScreenScanner screen);
    
    /**
     * @param screen
     */
    void removeScreen(ScreenScanner screen);
private: 
    forward_list<ScreenScanner> screens;
    DataSender dataSender;
    uint8 sentDataCount;
    uint8 receivedDataCount;
};

#endif //_SCREENSENDER_H