/**
 * Project ElteRemoteControl
 * @author Zsolt German
 * @version 0.1
 */


#ifndef _COLORCONVERTER_H
#define _COLORCONVERTER_H

class ColorConverter {
public: 
    
    /**
     * @param color
     */
    static uint32 toValue(uint8[] color);
    
    /**
     * @param value
     */
    static uint8[] toColor(uint32 value);
    
    /**
     * @param value
     * @param size
     */
    static uint8* toColors(uint32* value, uint size);
};

#endif //_COLORCONVERTER_H