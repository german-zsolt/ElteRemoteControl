/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _CONTACTDATA_H
#define _CONTACTDATA_H

class ContactData {
public: 
    string username;
    DateTime lastActive;
    ConnectionData connectionData;
};

#endif //_CONTACTDATA_H