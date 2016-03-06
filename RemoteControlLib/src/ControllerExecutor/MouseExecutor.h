/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _MOUSEEXECUTOR_H
#define _MOUSEEXECUTOR_H

#include "ControllerExecutor.h"


class MouseExecutor: public ControllerExecutor {
public: 
    
    /**
     * @param changes
     */
    static void doChanges(MouseButtonState changes);
    
    /**
     * @param changes
     */
    static void doChanges(MousePositionState changes);
    
    /**
     * @param changes
     */
    static void doChanges(MouseScrollState changes);
};

#endif //_MOUSEEXECUTOR_H