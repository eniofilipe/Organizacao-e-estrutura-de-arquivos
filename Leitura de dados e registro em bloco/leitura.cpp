#include <iostream>
#include <string>
#include <fstream>
#include "Pessoa.h"


using namespace std;


int main(){

    Pessoa enio;

    fstream arquivo;
    //fstream novoArquivo;


    arquivo.open("PessoasNovo.txt", ios::in );
    //novoArquivo.open("PessoasNovo.txt",ios::out);
    arquivo.unsetf(ios::skipws);
    if ( !arquivo.good()  )
    {
        cout<<"ERRO ao abrir arquivo!";
        exit(1);
    }   
    
    while(enio.lerPessoa(arquivo)){
        cout<<"------------------------------------"<<endl;
        enio.mostraTela();
    }
    

    exit(0);
}