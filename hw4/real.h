#ifndef __REAL_H__
#define __REAL_H__
#include "token.h"

class Real : public Token
{
    const float value;
public:
    Real();
    Real(float v);
    std::string toString();
};

#endif
