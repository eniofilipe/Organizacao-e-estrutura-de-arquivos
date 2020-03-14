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

//constructors
Pessoa::Pessoa(){
    nome = "";
    sobrenome = "";
    telefone = "";

    codigo = 0;

    novaData.setDataNascimento(1,1,1);
}

//Construtor cheio
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

//Faz a leitura do dado no arquivo de entrada e escreve no arquivo de saida
bool Pessoa::lerPessoa(fstream &arqIn, fstream &arqOut){
    
    //verifica se o arquivo de entrada é válido
    if( !arqIn.good() )
        return false;

    char campo[100];
    int dia, mes, ano;

    //Lê uma cadeia de caracteres de certo tamanho no arquivo até um delimitador getline(char*[], tamanho, delimitador)
    arqIn.getline(campo, 100, '|');
    codigo = atoi(campo);
    
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

    novaData.setDataNascimento(dia,mes,ano);
    stringstream aux;

    //Concatena os dados numa string para serem registrados no novo arquivo
    aux<<"|"<<nome<<"|"<<sobrenome<<"|"<<telefone<<"|"<<getDataNascimento();
    //Lê o tamanho do bloco do registro 
    short tam =  aux.str().length() + sizeof(int);
    //Escreve no arquivo o tamanho do bloco em bytes
    arqOut.write(reinterpret_cast<const char*>(&tam), sizeof(short));
    //Escreve o bloco no arquivo
    arqOut.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
    arqOut.write(aux.str().c_str(), tam-sizeof(int));

    return true;
}

// Mostra os dados na tela
void Pessoa::mostraTela(){
    cout<<"Código: "<<codigo<<endl;
    cout<<"Nome: "<<nome<<endl;
    cout<<"Sobrenome: "<<sobrenome<<endl;
    cout<<"Telefone: "<<telefone<<endl;
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<novaData.getDia()<<"/"<<setw(2)<<novaData.getMes()<<"/"<<setw(4)<<novaData.getAno();
    cout<<"Data de nascimento: "<<aux.str()<<endl;

}