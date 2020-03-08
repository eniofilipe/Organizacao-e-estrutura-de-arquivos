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
#include "DataNascimento.h"

using namespace std;

class Pessoa {

    private:
        std::string nome, sobrenome, telefone;
        DataNascimento novaData;
    public:
        ///constructor
        Pessoa();
        Pessoa(std::string nome, std::string sobrenome, std::string telefone, int dia, int mes, int ano);

        //setters 
        void setNome(std::string nome);
        void setSobrenome(std::string sobrenome);
        void setTelefone(std::string telefone);
        bool setDataNascimento(int dia, int mes, int ano);

        //getters
        std::string getNome();
        std::string getSobrenome();
        std::string getTelefone();
        std::string getDataNascimento();

        ///Mostrar na tela
        void mostraTela();

        //Ler do Arquivo
        bool lerPessoa(fstream &arqIn, fstream &arqOut);
};
