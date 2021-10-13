#include "num.h"

// variable initialization
Num::Num() : value(0) {}

// variables initialization
Num::Num(int v) : Token(t.NUM), value(v) {}

// to_string() changes char to string
std::string Num::toString()
{
    return std::to_string(value);
}
