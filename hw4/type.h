#ifndef __TYPE_H__
#define __TYPE_H__
#include "word.h"

class Type : public Word
{
public:
    int width;
    Type();
    Type(std::string s, int tag, int w);
    //static bool numeric(Type p);
    //static Type max(Type p1, Type p2);
};

// static local objects
static Type Int("int", t.BASIC, 4);
static Type Float("float", t.BASIC, 8);
static Type Char("char", t.BASIC, 1);
static Type Bool("bool", t.BASIC, 1);

#endif
