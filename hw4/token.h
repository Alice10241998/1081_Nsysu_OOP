#ifndef __TOKEN_H__
#define __TOKEN_H__
#include "tag.h"
#include <string>

class Token
{
public:
    int tag;
    Token();
    Token(int t);
    void mark(int tag);

    // polymorphous method
    virtual std::string toString();
};

#endif
