#ifndef DATANASCIMENTO_H_
#define DATANASCIMENTO_H_
#endif

#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class DataNascimento {

    private:
        int dia, mes, ano;
        bool DataValida(int dia, int mes, int ano);
    
    public:
        DataNascimento();
        DataNascimento(int dia, int mes, int ano);

        bool setDataNascimento(int dia, int mes, int ano);

        std::string getDataNascimento();
        int getDia();
        int getMes();
        int getAno();

};