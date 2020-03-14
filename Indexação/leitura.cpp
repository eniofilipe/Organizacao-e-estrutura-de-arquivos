/*
*****************************************************************
*  Trabalho Organização e Estrutura de Arquivos                 *
*  -- Leitura de dados em bloco                                 *  
*  -- Ênio Filipe e Marcos Dias.                                *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Pessoa.h"


using namespace std;


int main(){

    //Inicializa instância objeto Pessoa
    Pessoa enio;

    //Inicializa variável de arquivo de entrada
    ifstream arquivo;
    fstream novoArquivo, arquivoIndexEscrita, arquivoIndexLeitura;
    //Inicializa arquivo de entrada e testa validade do arquivo
    arquivo.open("PessoasNovo.txt", ios::in );
    novoArquivo.open("RegistrosOrdenados.txt",ios::out);
    arquivoIndexEscrita.open("indexes.txt",ios::out);

    arquivo.unsetf(ios::skipws);
    if ( !arquivo.good()  )
    {
        cout<<"ERRO ao abrir arquivo!";
        exit(1);
    }
    //Faz a leitura dos dados e imprime os dados na tela   
    enio.imprimeCabecalho();
    while(enio.lerPessoa(arquivo));

    enio.ordenaLista();
    enio.imprimeLista();
    enio.salvaIndex(arquivoIndexEscrita);
    arquivo.close();
    arquivo.open("PessoasNovo.txt", ios::in );
    arquivoIndexEscrita.close();
    arquivoIndexLeitura.open("indexes.txt", ios::in);
    enio.registrosOrdenados(arquivo, arquivoIndexLeitura, novoArquivo);
    arquivo.close();
    novoArquivo.close();
    arquivoIndexLeitura.close();

    exit(0);
}