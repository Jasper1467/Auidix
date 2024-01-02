#ifndef CSAFETY_H
#define CSAFETY_H

#include <functional>

#include "Types.h"
#include "CAudioDevice.h"

enum SafetyFlags_e
{
    SAFETYFLAG_NONE = 0,

    // Decibel
    SAFETYFLAG_DECIBEL_UNSAFE_RESOLVED,
    SAFETYFLAG_DECIBEL_UNSAFE_UNRESOLVED,
    SAFETYFLAG_DECIBEL_SAFE,


    // Hertz
    SAFETYFLAG_HERTZ_UNSAFE_RESOLVED,
    SAFETYFLAG_HERTZ_UNSAFE_UNRESOLVED,
    SAFETYFLAG_HERTZ_SAFE,

    SAFETYFLAG_MAX,
};

class CSafety
{
public:
    void Check(AudioData_t& Data, const std::function<void(SafetyFlags_e)>& OnUnsafe) const;

    CSafety(Decibel MaxDecibel, Hertz MaxHertz, bool bResolve) : m_MaxDecibel(MaxDecibel), m_MaxHertz(MaxHertz), m_bResolve(bResolve) {}
    CSafety(Decibel MaxDecibel, KHertz MaxKHertz, bool bResolve) : m_MaxDecibel(MaxDecibel), m_bResolve(bResolve)
    {

    }

private:
    Decibel m_MaxDecibel = 0;
    Hertz m_MaxHertz = 0;
    bool m_bResolve = false;
};
#endif //CSAFETY_H
