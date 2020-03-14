#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <type_traits>
#include "Pessoa.h"
using namespace std;


//constructors
Pessoa::Pessoa(){
    nome = "";
    sobrenome = "";
    telefone = "";

    codigo = 0;

    novaData.setDataNascimento(1,1,1);

}

Pessoa::Pessoa(string nome, string sobrenome, string telefone, int dia, int mes, int ano, int codigo){

    this->nome = nome;
    this->sobrenome = sobrenome;
    this->telefone = telefone;
    this->codigo = codigo;

    novaData.setDataNascimento(dia,mes,ano);   

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
    return novaData.setDataNascimento(dia,mes,ano);
}
void Pessoa::setCodigo(int codigo){
    this->codigo = codigo;
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
    
    return novaData.getDataNascimento();
    
}
int Pessoa::getCodigo(){
    return codigo;
}

bool Pessoa::lerPessoa(fstream &arqIn){
    
    //Testa validade do arquivo de entrada
    if( !arqIn.good() && arqIn.eof())
        return false;
    
    char campo[100], diaAux[10], mesAux[10], anoAux[10];
    int dia, mes, ano;

    short tamanho;
    //Lê no arquivo, o tamanho do bloco a ser lido a seguir
    arqIn.read(reinterpret_cast<char*>(&tamanho), sizeof(short));

    if( !arqIn.good() && arqIn.eof())
        return false;

    //Lê código, tamanho de variável do tipo inteiro
    arqIn.read(reinterpret_cast<char*>(&codigo), sizeof(int));

    //Lê no arquivo o bloco de dados de acordo com o tamanho lido anteriormente
    arqIn.read(campo,tamanho-sizeof(int));
    
    stringstream aux(campo);

    //Trata o bloco lido, colocando as informações no variáveis correspondentes
    getline(aux,nome,'|');
    getline(aux,nome,'|');
    getline(aux,sobrenome,'|');
    getline(aux,telefone,'|');
    aux.getline(diaAux,3,'/');
    aux.getline(mesAux,3,'/');
    aux.getline(anoAux,5,'&');

    dia = atoi(diaAux);
    mes = atoi(mesAux);
    ano = atoi(anoAux);

    novaData.setDataNascimento(dia, mes, ano);

    return true;
}

//Imprime na tela o cabaçalho da tabela com os dados
void Pessoa::imprimeCabecalho(){
    cout<<setfill('-')<<setw(82)<<'-'<<endl;
    cout<<"| "<<"CODIGO"<<setfill(' ')<<setw(4);
    cout<<"| "<<"NOME"<<setfill(' ')<<setw(21);
    cout<<" | "<<"SOBRENOME"<<setfill(' ')<<setw(6);
    cout<<" | "<<"TELEFONE"<<setfill(' ')<<setw(10);
    cout<<" | "<<"DT NASC"<<setfill(' ')<<setw(6)<<" | "<<endl;
    cout<<setfill('-')<<setw(82)<<'-'<<endl;
}
//Imprime na tela os dados organizados em tabela
void Pessoa::mostraTela(){

    stringstream codigoStream;
    codigoStream << codigo;
    cout<<"| "<<codigoStream.str()<<setw(10 - codigoStream.str().length())<<setfill(' ');
    cout<<"| "<<nome<<setw(25 - nome.length())<<setfill(' ')<<" | ";
    cout<<sobrenome<<setfill(' ')<<setw(15 - sobrenome.length())<<" | ";
    cout<<telefone<<" | ";
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<novaData.getDia()<<"/"<<setw(2)<<novaData.getMes()<<"/"<<setw(4)<<novaData.getAno()<<" | ";
    cout<<aux.str()<<endl;
    cout<<setfill('-')<<setw(82)<<'-'<<endl;
}