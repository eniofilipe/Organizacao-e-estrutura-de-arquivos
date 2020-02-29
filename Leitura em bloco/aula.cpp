#include <iostream>
#include <string>
#include <fstream>
#include "Pessoa.h"


using namespace std;


int main(){

    Pessoa enio;

    fstream arquivo,novoArquivo;


    char linha[200];
    arquivo.open("Pessoas.txt", ios::in );
    novoArquivo.open("PessoasNovo.txt",ios::out);
    arquivo.unsetf(ios::skipws);
    if ( arquivo.good()  )
    {
        arquivo.getline(linha, 100, '\n');
        cout<<linha<<endl;
    }
    else
    {
        cout<<"ERRO ao abrir arquivo!";
        exit(1);
    }   
    
    while(enio.lerPessoa(arquivo, novoArquivo)){
        cout<<"--------------------------------------------"<<endl;
        enio.mostraTela();
    }
    novoArquivo.close();

    exit(0);
}