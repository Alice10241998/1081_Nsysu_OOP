#include "word.h"

Word::Word()
{
    lexeme = "";
}

Word::Word(std::string s, int tag) : Token(tag)
{
    lexeme = s;
}

std::string Word::toString()
{
    return lexeme;
}
