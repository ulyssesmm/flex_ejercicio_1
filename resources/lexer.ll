%{
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Lexer.hpp"
#undef YY_DECL
#define YY_DECL int Lexer::yylex()
string mayusculas;
%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="Lexer"
%option yylineno

letra [a-z]

%%

{letra}+  { mayusculas = yytext;
            transform(mayusculas.begin(), mayusculas.end(), mayusculas.begin(),
                [](unsigned char c){ return  toupper(c);});
                /*Añadir el codigo para escribir en salida la nueva cadena*/
            }
\n          { 
                yylineno++; 
                salida<<endl;
            }

<<EOF>>     {
                salida.close();
            }

.          { 
                salida<<yytext;
            }
%%
/*Sección de código de usuario*/
int yyFlexLexer::yywrap(){
    return 1;
}

int Lexer::getLine(){
    return yylineno;
}

string Lexer::getTokVal(){
    return yytext;
}

char Lexer::upper(char c){
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}