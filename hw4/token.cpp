#include "token.h"
#include <iostream>

Token::Token()
{
    tag = 0;
}

Token::Token(int t)
{
    tag = t;
}

std::string Token::toString()
{
    char a = (char)tag;
    return std::string(1, a);
}

void Token::mark(int tag)
{
    switch(tag) {
		case 256:
			std::cout << "AND";
			break;
		case 257:
			std::cout << "BASIC";
			break;
		case 258:
			std::cout << "BREAK";
			break;
		case 259:
			std::cout << "DO";
			break;
		case 260:
			std::cout << "ELSE";
			break;
		case 261:
			std::cout << "EQ";
			break;
		case 262:
			std::cout << "FALSE";
			break;
		case 263:
			std::cout << "GE";
			break;
		case 264:
			std::cout << "ID";
			break;
		case 265:
			std::cout << "IF";
			break;
		case 266:
			std::cout << "INDEX";
			break;
		case 267:
			std::cout << "LE";
			break;
		case 268:
			std::cout << "MINUS";
			break;
		case 269:
			std::cout << "NE";
			break;
		case 270:
			std::cout << "NUM";
			break;
		case 271:
			std::cout << "OR";
			break;
		case 272:
			std::cout << "REAL";
			break;
		case 273:
			std::cout << "TEMP";
			break;
		case 274:
			std::cout << "TRUE";
			break;
		case 275:
			std::cout << "WHILE";
			break;
		default:
			std::cout << (char)tag;
			break;
	}
}
