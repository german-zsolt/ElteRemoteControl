/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _DATASENDER_H
#define _DATASENDER_H

class DataSender {
public: 
    
    /**
     * @param protocol
     * @param ip
     * @param mac
     * @param port
     */
    void initConnection(string protocol, string ip, string mac, int port);
    
    /**
     * @param data
     * @param size
     */
    void sendData(uint8* data, uint32 size);
    
    void closeConnection();
private: 
    int socket;
    string privateKey;
    string publicKey;
};

#endif //_DATASENDER_H