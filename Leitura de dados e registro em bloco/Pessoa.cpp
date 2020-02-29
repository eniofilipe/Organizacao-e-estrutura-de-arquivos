#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <type_traits>

using namespace std;
#include "Pessoa.h"


const int dias[] = {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
#define BISSEXTO(ano) (ano%400==0 ||(ano%4==0 && ano%100!=0))

//constructors
Pessoa::Pessoa(){
    nome = "";
    sobrenome = "";
    telefone = "";

    dia = mes = ano = 1;
}

Pessoa::Pessoa(string nome, string sobrenome, string telefone, string dataNascimento){

    this->nome = nome;
    this->sobrenome = sobrenome;
    this->telefone = telefone;

}

bool Pessoa::DataValida(int dia, int mes, int ano){
    if( ano > 0 && mes > 0 && mes <= 12 && dia > 0){
        if(BISSEXTO(ano) && mes==2){
            return ( dia <=29 );
        }

        return ( dia <= dias[mes-1]);
    }
    return false;
}

//setters
void Pessoa::setNome(string nome){
    this->nome = nome;
}
void Pessoa::setSobrenome(string sobrenome){
    this->sobrenome = sobrenome;
}
void Pessoa::setTelefone(std::string telefone){
    this->telefone = telefone;
}
bool Pessoa::setDataNascimento(int dia, int mes, int ano){
    if( DataValida (dia, mes, ano)){
    
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        return true;
    }
    return false;
}

//getters
string Pessoa::getNome(){
    return nome;
}
string Pessoa::getSobrenome()
{
    return sobrenome;
}
string Pessoa::getTelefone(){
    return telefone;
}
string Pessoa::getDataNascimento(){
    
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<ano;
    return aux.str();
}

bool Pessoa::lerPessoa(fstream &arqIn){
    
    if( !arqIn.good() && arqIn.eof())
        return false;
    
    char campo[100], diaAux[10], mesAux[10], anoAux[10];

    int tamanho;

  
    arqIn.getline(campo, 4, '|');
    tamanho = atoi(campo);

    if( !arqIn.good() && arqIn.eof())
        return false;

    arqIn.getline(campo, tamanho, '&');
    
    stringstream aux(campo);

    getline(aux,nome,'|');
    getline(aux,sobrenome,'|');
    getline(aux,telefone,'|');
    aux.getline(diaAux,3,'/');
    aux.getline(mesAux,3,'/');
    aux.getline(anoAux,5,'&');

    dia = atoi(diaAux);
    mes = atoi(mesAux);
    ano = atoi(anoAux);


    /*
    
    // VERIFICAR QUAL SISTEMA OPERACIONAL
    #ifdef defined(_WIN32) || defined(WIN32)
    arqIn.getline(campo, 5, '\n');
    #else
    arqIn.getline(campo, 6, '\n');
    #endif
    ano = atoi(campo);
    

    stringstream aux, auxOut;

    aux<<"|"<<nome<<"|"<<sobrenome<<"|"<<telefone<<"|"<<getDataNascimento();

    cout<<aux.str()<<" TAMANHO = "<<aux.str().length()<<endl;
    auxOut<<aux.str().length()<<aux.str();
    cout<<auxOut.str()<<endl;
    arqOut<<auxOut.str();

    */

    return true;
}

bool Pessoa::escreveArquivo(fstream &arqOut){

}


void Pessoa::mostraTela(){

    cout<<"Nome: "<<nome<<endl;
    cout<<"Sobrenome: "<<sobrenome<<endl;
    cout<<"Telefone: "<<telefone<<endl;
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<ano;
    cout<<"Data de nascimento: "<<aux.str()<<endl;

}