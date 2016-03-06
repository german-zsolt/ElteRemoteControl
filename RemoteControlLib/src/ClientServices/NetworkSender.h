/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _NETWORKSENDER_H
#define _NETWORKSENDER_H

class NetworkSender {
public: 
    
    /**
     * @param username
     */
    string requestRemoteAccess(string username);
    
    /**
     * @param username
     */
    string requestRemoteHelp(string username);
    
    /**
     * @param username
     * @param portTcp
     */
    string acceptRemoteAccess(string username, int portTcp);
    
    /**
     * @param username
     * @param portTcp
     */
    string acceptRemoteHelp(string username, int portTcp);
private: 
    int socket;
};

#endif //_NETWORKSENDER_H