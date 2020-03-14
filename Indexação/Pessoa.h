#ifndef PESSOA_H_
#define PESSOA_H_
#endif 

#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include "DataNascimento.h"
using namespace std;

class Pessoa {

    private:
        std::string nome, sobrenome, telefone;
        DataNascimento novaData;
        int codigo;
        int offset;
        list <vector<int>> listaDeRegistros;
        
    public:
        ///constructor
        Pessoa();
        Pessoa(std::string nome, std::string sobrenome, std::string telefone, int dia, int mes, int ano, int codigo, int offset);

        //setters 
        void setNome(std::string nome);
        void setSobrenome(std::string sobrenome);
        void setTelefone(std::string telefone);
        bool setDataNascimento(int dia, int mes, int ano);
        void setCodigo(int codigo);
        void setOffset(int offset);

        //getters
        std::string getNome();
        std::string getSobrenome();
        std::string getTelefone();
        std::string getDataNascimento();
        int getCodigo();
        int getOffset();
        
        ///Mostrar na tela
        void mostraTela();
        void imprimeCabecalho();

        //Ordena Lista
        void ordenaLista();

        //Imprime Lista
        void imprimeLista();

        //Salva indexes ordenados em arquivo de saída
        void salvaIndex(fstream &arqOut);

        //Novo arquivo com registros ordenados
        void registrosOrdenados(ifstream &arqIn, fstream &index, fstream &arqOut);

        //Ler do Arquivo
        bool lerPessoa(ifstream &arqIn);
};
