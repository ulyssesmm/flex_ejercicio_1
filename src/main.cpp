#include <iostream>
#include <fstream>
using namespace std;

#include "Lexer.hpp"


int main(int argc, char *argv[])
{
	if(argc <2){
		cout <<"Faltan argumentos"<<endl;
		exit(EXIT_FAILURE);
	}
	filebuf fb;
	fb.open(string(argv[1]), ios::in);
	if(!fb.is_open()){
		cout<<"El archivo no existe o no tienes permisos"<<endl;
		exit(EXIT_FAILURE);
	}

	istream is(&fb);
	Lexer lexer(&is);
	int token = lexer.yylex();
	while( token != 0){
		token = lexer.yylex();
	}
	fb.close();
}