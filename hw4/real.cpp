#include "real.h"

// variable initialization
Real::Real() : value(0) {}

// variables initialization
Real::Real(float v) : Token(t.REAL), value(v) {}

// to_string() changes char to string
std::string Real::toString()
{
    return std::to_string(value);
}
