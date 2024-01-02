#include "CSafety.h"

void CSafety::Check(AudioData_t& Data, const std::function<void(SafetyFlags_e)>& OnUnsafe) const
{
    int nFlags = SAFETYFLAG_DECIBEL_SAFE | SAFETYFLAG_HERTZ_SAFE;

    if (Data.m_Decibel > m_MaxDecibel)
    {
        nFlags |= m_bResolve ? SAFETYFLAG_DECIBEL_UNSAFE_RESOLVED : SAFETYFLAG_DECIBEL_UNSAFE_UNRESOLVED;
        nFlags &= ~SAFETYFLAG_DECIBEL_SAFE;

        if (m_bResolve)
            Data.m_Decibel = m_MaxDecibel;
    }

    if (Data.m_Hertz > m_MaxHertz)
    {
        nFlags |= m_bResolve ? SAFETYFLAG_HERTZ_UNSAFE_RESOLVED : SAFETYFLAG_HERTZ_UNSAFE_UNRESOLVED;
        nFlags &= ~SAFETYFLAG_HERTZ_SAFE;

        if (m_bResolve)
            Data.m_Decibel = m_MaxJERTZ;
    }

    OnUnsafe(static_cast<SafetyFlags_e>(nFlags));
}
