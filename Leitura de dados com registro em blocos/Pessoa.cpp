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

//Constantes para teste de datas
const int dias[] = {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
#define BISSEXTO(ano) (ano%400==0 ||(ano%4==0 && ano%100!=0))

//constructors
Pessoa::Pessoa(){
    nome = "";
    sobrenome = "";
    telefone = "";

    dia = mes = ano = 1;
}

//Construtor cheio
Pessoa::Pessoa(string nome, string sobrenome, string telefone, string dataNascimento){

    this->nome = nome;
    this->sobrenome = sobrenome;
    this->telefone = telefone;

}

//Função que confere a validade da data 
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
    
    //Concatena os dados da data (dia, mes, ano) para formato dia/mes/ano
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<ano;
    return aux.str();
}

//Faz a leitura do dado no arquivo de entrada e escreve no arquivo de saida
bool Pessoa::lerPessoa(fstream &arqIn, fstream &arqOut){
    
    //verifica se o arquivo de entrada é válido
    if( !arqIn.good() )
        return false;

    char campo[100];

    //Lê uma cadeia de caracteres de certo tamanho no arquivo até um delimitador getline(char*[], tamanho, delimitador)
    arqIn.getline(campo, 100, '|');
    nome = campo;
    
    arqIn.getline(campo, 100, '|');
    sobrenome = campo;
    
    arqIn.getline(campo, 100, '|');
    telefone = campo;
 
    arqIn.getline(campo, 3, '/');
    dia = atoi(campo);
    
    arqIn.getline(campo, 3, '/');
    mes = atoi(campo);

    // VERIFICAR QUAL SISTEMA OPERACIONAL
    #ifdef defined(_WIN32) || defined(WIN32)
    arqIn.getline(campo, 5, '\n');
    #else
    arqIn.getline(campo, 6, '\n');
    #endif
    ano = atoi(campo);

    stringstream aux;

    //Concatena os dados numa string para serem registrados no novo arquivo
    aux<<nome<<"|"<<sobrenome<<"|"<<telefone<<"|"<<getDataNascimento();
    //Lê o tamanho do bloco do registro 
    short tam =  aux.str().length();
    //Imprime na tela a string e informa o tamanho lido
    cout<<aux.str()<<" TAMANHO = "<<tam<<endl;
    //Escreve no arquivo o tamanho do bloco em bytes
    arqOut.write(reinterpret_cast<const char*>(&tam), sizeof(short));
    //Escreve o bloco no arquivo
    arqOut.write(aux.str().c_str(), tam);

    return true;
}

// Mostra os dados na tela
void Pessoa::mostraTela(){

    cout<<"Nome: "<<nome<<endl;
    cout<<"Sobrenome: "<<sobrenome<<endl;
    cout<<"Telefone: "<<telefone<<endl;
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes<<"/"<<setw(4)<<ano;
    cout<<"Data de nascimento: "<<aux.str()<<endl;

}