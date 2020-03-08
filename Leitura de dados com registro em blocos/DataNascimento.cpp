#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <type_traits>
#include "DataNascimento.h"
using namespace std;


//Constantes para teste de validade da data
const int dias[] = {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
#define BISSEXTO(ano) (ano%400==0 ||(ano%4==0 && ano%100!=0))

DataNascimento::DataNascimento(){
    dia = mes = ano = 1;
}

DataNascimento::DataNascimento(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

bool DataNascimento::DataValida(int dia, int mes, int ano){
    if( ano > 0 && mes > 0 && mes <= 12 && dia > 0){
        if(BISSEXTO(ano) && mes==2){
            return ( dia <=29 );
        }

        return ( dia <= dias[mes-1]);
    }
    return false;
}

bool DataNascimento::setDataNascimento(int dia, int mes, int ano){
    if(DataValida(dia,mes,ano)){
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        
        return true;
    }        
    return false;
}

string DataNascimento::getDataNascimento(){
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<ano;
    return aux.str();
}

int DataNascimento::getDia(){return dia;}

int DataNascimento::getMes(){return mes;}

int DataNascimento::getAno(){return ano;}