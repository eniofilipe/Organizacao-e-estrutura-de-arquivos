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

//Constantes para teste de validade da data
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

//Teste de validade da data
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
    
    //Concatena informações da data em formato dia/mes/ano
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<ano;
    return aux.str();
}

bool Pessoa::lerPessoa(fstream &arqIn){
    
    //Testa validade do arquivo de entrada
    if( !arqIn.good() && arqIn.eof())
        return false;
    
    char campo[100], diaAux[10], mesAux[10], anoAux[10];

    short tamanho;
    //Lê no arquivo, o tamanho do bloco a ser lido a seguir
    arqIn.read(reinterpret_cast<char*>(&tamanho), sizeof(short));

    if( !arqIn.good() && arqIn.eof())
        return false;

    //Lê no arquivo o bloco de dados de acordo com o tamanho lido anteriormente
    arqIn.read(campo,tamanho);
    
    stringstream aux(campo);

    //Trata o bloco lido, colocando as informações no variáveis correspondentes
    getline(aux,nome,'|');
    getline(aux,sobrenome,'|');
    getline(aux,telefone,'|');
    aux.getline(diaAux,3,'/');
    aux.getline(mesAux,3,'/');
    aux.getline(anoAux,5,'&');

    dia = atoi(diaAux);
    mes = atoi(mesAux);
    ano = atoi(anoAux);

    return true;
}

//Imprime na tela o cabaçalho da tabela com os dados
void Pessoa::imprimeCabecalho(){
    cout<<setfill('-')<<setw(72)<<'-'<<endl;
    cout<<"| "<<"NOME"<<setfill(' ')<<setw(21);
    cout<<" | "<<"SOBRENOME"<<setfill(' ')<<setw(6);
    cout<<" | "<<"TELEFONE"<<setfill(' ')<<setw(10);
    cout<<" | "<<"DT NASC"<<setfill(' ')<<setw(6)<<" | "<<endl;
    cout<<setfill('-')<<setw(72)<<'-'<<endl;
}
//Imprime na tela os dados organizados em tabela
void Pessoa::mostraTela(){

    cout<<"| "<<nome<<setw(25 - nome.length())<<setfill(' ')<<" | ";
    cout<<sobrenome<<setfill(' ')<<setw(15 - sobrenome.length())<<" | ";
    cout<<telefone<<" | ";
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<ano<<" | ";
    cout<<aux.str()<<endl;
    cout<<setfill('-')<<setw(72)<<'-'<<endl;
}