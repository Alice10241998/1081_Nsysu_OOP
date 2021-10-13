#ifndef __LEXER_H__
#define __LEXER_H__
#include "num.h"
#include "real.h"
#include "word.h"
#include "type.h"
#include <fstream>

class Hashtable
{
public:
    // public variables
    std::string str;
    Word word;

    // constructor
    Hashtable();

    // methods
    Word* get();
    void put(std::string s, Word* w);
    bool cmp(std::string s);
};

class Lexer
{
public:
    // static local variable
    static int line;

    // constructor
    Lexer();

    // methods
    void openfile(char *filename);
    void closefile();
    bool iseof();
    Token* scan();
    void readch();          // read a char
    bool readch(char c);    // true if next char is c
    void reserve(Word w);   // push to hashtable
private:
    char peek;
    int hash_index;
    std::ifstream file;     // fstream object
    Hashtable hashtable[100];
};

#endif
