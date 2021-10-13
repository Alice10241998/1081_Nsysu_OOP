#ifndef __WORD_H__
#define __WORD_H__
#include "token.h"

class Word : public Token
{
public:
    std::string lexeme;
    Word();
    Word(std::string s, int tag);
    std::string toString();
};

// static local objects
static Word And("&&", t.AND);
static Word Or("||", t.OR);
static Word Eq("==", t.EQ);
static Word Ne("!=", t.NE);
static Word Le("<=", t.LE);
static Word Ge(">=", t.GE);
static Word Minus("minus", t.MINUS);
static Word True("true", t.TRUE);
static Word False("false", t.FALSE);
static Word Temp("t", t.TEMP);

#endif
