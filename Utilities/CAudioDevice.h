#ifndef CAUDIODEVICE_H
#define CAUDIODEVICE_H

#include "Types.h"

struct AudioData_t
{
    Decibel m_Decibel;
    Hertz m_Hertz;
};

class CAudioDevice
{
public:
    AudioData_t m_Data;
};



#endif //CAUDIODEVICE_H
