#ifndef __NUM_H__
#define __NUM_H__
#include "token.h"

class Num : public Token
{
    const int value;
public:
    Num();
    Num(int v);
    std::string toString();
};

#endif
