/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _POSITIONCONVERTER_H
#define _POSITIONCONVERTER_H

class PositionConverter {
public: 
    int16[] offsetOriginal;
    int16[] offsetTarget;
    uint16[] sizeOriginal;
    uint16[] sizeTarget;
    
    /**
     * @param positionOriginal
     */
    int16[] getPositionTarget(int16[] positionOriginal);
};

#endif //_POSITIONCONVERTER_H