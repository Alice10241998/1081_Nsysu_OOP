#include "lexer.h"
#include <iostream>

Hashtable::Hashtable()
{
    str = "";
}

Word* Hashtable::get()
{
    return &word;
}

bool Hashtable::cmp(std::string s)
{
    if(s.compare(str) == 0)
        return true;
    else
        return false;
}

void Hashtable::put(std::string s, Word* w)
{
    str = s;
    word = Word(w->lexeme, w->tag);
}

// the lines in test program
int Lexer::line = 1;

Lexer::Lexer()
{
    // assignment private variables
    peek = ' ';
    hash_index = 0;

    // pre-put the reserved keywords
    reserve(Word("if", t.IF));
    reserve(Word("else", t.ELSE));
    reserve(Word("while", t.WHILE));
    reserve(Word("do", t.DO));
    reserve(Word("break", t.BREAK));
    reserve(True);
    reserve(False);
    reserve(Int);
    reserve(Char);
    reserve(Bool);
    reserve(Float);
}

Token* Lexer::scan()
{
    // skip spaces, tabs, and newline
    // if newline --> line = line + 1
    for(;;readch())
    {
        if(peek == ' ' || peek == '\t')
            continue;
        else if(peek == '\n')
            line += 1;
        else
            break;
    }

    // if peek == one of operators(&, |, =, !, <, >)
    // see next whether it is a double-length operator
    // Word(): &&, ||, ==, !=, <=, >= if peek next corrects
    // Token(): &,  | , = , ! , < , >  otherwise
    switch(peek)
    {
        case '&':
            if(readch('&'))
                return &And;
            else
                return new Token('&');
            break;
        case '|':
            if(readch('|'))
                return &Or;
            else
                return new Token('|');
            break;
        case '=':
            if(readch('='))
                return &Eq;
            else
                return new Token('=');
            break;
        case '!':
            if (readch('='))
                return &Ne;
            else
                return new Token('!');
            break;
        case '<':
            if (readch('='))
                return &Le;
            else
                return new Token('<');
            break;
        case '>':
            if (readch('='))
                return &Ge;
            else
                return new Token('>');
            break;
    }

    // if peek is a digit
    if(isdigit(peek))
    {
        // finish reading the num
        int v = 0;
        while(isdigit(peek))
	{
            v = 10 * v + peek - '0';
            readch();
        }

        // 不是小數 是整數
        if(peek != '.')
            return new Num(v);

        //是浮點數
        float x = v;    // store the integer part
        float d = 10;   // radix is 10
        for(;;)
        {
            readch();
            // stop when peek is not digit
            if(!isdigit(peek))
                break;
            // integer + (digit / 10)
            x = x + (peek - '0') / d;
            // radix exponent adds 10 -> 100 -> 100 ...
            // then we can get 0.x -> 0.0x -> 0.00x ...
            d = d * 10;
        }
        // return real number object
        return new Real(x);
    }

    // if peek is an alphabet
    // it can be "reserved keywords" or "variable names"
    if(isalpha(peek))
    {
        // finish reading the word
        std::string b = "";
        while(isalpha(peek) || isdigit(peek))
	{
            b += peek;
            readch();
        }
        // note: digits can be included in variable name

        // search in hashtable to find the same keyword
        for(int i = 0; i < 100; i++)
        {
            if(hashtable[i].cmp(b))
            {
                // if compare successes
                // then it is a keyword or an already-read variable name
                Word* w = hashtable[i].get();
                return w;
            }
        }

        // if not in hashtable
        // then it is a new variable name
        // stores it in hashtable
        Word* w = new Word(b, t.ID);
        hashtable[hash_index++].put(b, w);
        return w;
    }

    // other character like ';', '(', ')', '{', '}', '[', ']', '+', '-' ...
    Token* tok = new Token(peek);
    // reset peek
    peek = ' ';
    return tok;
}

void Lexer::openfile(char *filename)
{
    file.open(filename);
}

void Lexer::closefile()
{
    file.close();
}

bool Lexer::iseof()
{
    if(file.eof())
        return true;
    else
        return false;
}

// get one char at a time
void Lexer::readch()
{
    peek = file.get();
}

// if next peek is char c
bool Lexer::readch(char c)
{
    readch();
    if(peek != c)
        return false;
    // true case will return a Word object
    // so reset peek here
    peek = ' ';
    return true;
}

// store typename, keyword, variable name in hashtable
// max size is 100 (can be increased by modifing lexer.h)
void Lexer::reserve(Word w)
{
    if(hash_index > 99)
        std::cout << "***** hashtable overflow *****" << std::endl;
    else
        hashtable[hash_index++].put(w.lexeme, &w);
}
