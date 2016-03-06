/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _DATALISTENER_H
#define _DATALISTENER_H

class DataListener {
public: 
    
    /**
     * @param protocol
     * @param port
     */
    void initConnection(string protocol, int port);
private: 
    int socket;
    string privateKey;
    string publicKey;
    ScreenDisplayer screenDisplayer;
};

#endif //_DATALISTENER_H