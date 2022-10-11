#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include <string>
#include <fstream>
using namespace std;

class Lexer : public yyFlexLexer
{
public:
    Lexer(std::istream *in) : yyFlexLexer(in){
        salida.open("salida", ios::out);
    }
    ~Lexer() = default;
    using FlexLexer::yylex;
    virtual int yylex();

    int getLine();
    string getTokVal();
private:
    ofstream salida;
    int line = 1;
    char upper(char);

};

#endif // !__LEXER_HPP__
