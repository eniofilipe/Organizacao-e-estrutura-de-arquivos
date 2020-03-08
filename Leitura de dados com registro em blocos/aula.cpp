/*
*****************************************************************
*  Trabalho Organização e Estrutura de Arquivos                 *
*  -- Leitura de dados em arquivo e registro em bloco dos dados *
*     em outro arquivo.                                         *  
*  -- Ênio Filipe e Marcos Dias.                                *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Pessoa.h"


using namespace std;


int main(){

    //Instância do novo objeto do tipo Pessoa
    Pessoa enio;

    //Inicializa váriaveis dos arquivos de entrada e saída
    fstream arquivo,novoArquivo;

    //Inicialização dos arquivos e teste de abertura do arquivo de entrada
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
    

    //Realiza a leitura dos dados no arquivo de entrada enquanto escreve
    // no novo arquivo de saída e mostra na tela a lista de registros
    while(enio.lerPessoa(arquivo, novoArquivo)){
        cout<<"--------------------------------------------"<<endl;
        enio.mostraTela();
    }

    //Fecha arquivo de saída
    novoArquivo.close();

    exit(0);
}