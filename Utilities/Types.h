#ifndef TYPES_H
#define TYPES_H

typedef int Decibel;

typedef int Hertz;
typedef Hertz KHertz;

inline Hertz KHertzToHertz(const KHertz KHertz)
{
    return KHertz / 1000;
}

inline KHertz HertzToKHertz(const Hertz Hertz)
{
    return Hertz * 1000;
}

#endif //TYPES_H
