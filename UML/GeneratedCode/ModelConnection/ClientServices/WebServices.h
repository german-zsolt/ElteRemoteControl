/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _WEBSERVICES_H
#define _WEBSERVICES_H

class WebServices {
public: 
    
    static string[] generateSecurityKeys();
    
    /**
     * @param username
     * @param password
     */
    string register(string username, string password);
    
    string unRegister();
    
    /**
     * @param username
     * @param password
     * @param port
     */
    string login(string username, string password, uint16 port);
    
    string refreshStatus();
    
    string logout();
    
    string getUser();
    
    string getContacts();
    
    /**
     * @param search
     */
    string findContacts(string search);
    
    /**
     * @param username
     */
    string addContact(string username);
    
    /**
     * @param username
     */
    string acceptContact(string username);
    
    /**
     * @param username
     */
    string blockContact(string username);
    
    /**
     * @param username
     */
    string getConnectionData(string username);
private: 
    int socket;
    string loggedInUser;
    string loggedInPassword;
    string privateKey;
    string publicKey;
    Map<string;ContactData> contacts;
};

#endif //_WEBSERVICES_H