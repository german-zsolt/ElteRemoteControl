/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _KEYBOARDEXECUTOR_H
#define _KEYBOARDEXECUTOR_H

#include "ControllerExecutor.h"


class KeyboardExecutor: public ControllerExecutor {
public: 
    
    /**
     * @param changes
     */
    static void doChanges(KeyboardButtonState changes);
    
    /**
     * @param changes
     */
    static void doChanges(KeyboardLockState changes);
};

#endif //_KEYBOARDEXECUTOR_H