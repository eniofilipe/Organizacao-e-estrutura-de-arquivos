#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <type_traits>
#include "Pessoa.h"
using namespace std;


//constructors
Pessoa::Pessoa(){
    nome = "";
    sobrenome = "";
    telefone = "";

    codigo = 0;
    offset = 0;
    novaData.setDataNascimento(1,1,1);

}

Pessoa::Pessoa(string nome, string sobrenome, string telefone, int dia, int mes, int ano, int codigo, int offset){

    this->nome = nome;
    this->sobrenome = sobrenome;
    this->telefone = telefone;
    this->codigo = codigo;
    this->offset = offset;

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
void Pessoa::setOffset(int offset){
    this->offset = offset;
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
int Pessoa::getOffset(){
    return offset;
}

bool Pessoa::lerPessoa(ifstream &arqIn){
    
    //Testa validade do arquivo de entrada
    if( !arqIn.good() && arqIn.eof())
        return false;
    
    char campo[100], diaAux[10], mesAux[10], anoAux[10];
    int dia, mes, ano;

    offset = arqIn.tellg();
    short tamanho;
    //Lê no arquivo, o tamanho do bloco a ser lido a seguir
    arqIn.read(reinterpret_cast<char*>(&tamanho), sizeof(short));
    tamanho = tamanho + sizeof(short);
    if( !arqIn.good() && arqIn.eof())
        return false;

    //Lê código, tamanho de variável do tipo inteiro
    arqIn.read(reinterpret_cast<char*>(&codigo), sizeof(int));

    int indexReg[] = {codigo, offset};
    //Lê no arquivo o bloco de dados de acordo com o tamanho lido anteriormente
    arqIn.seekg(offset+tamanho);
    
    vector<int> registro (indexReg, indexReg + sizeof(indexReg) / sizeof(int) );
    listaDeRegistros.push_back(registro);

    /*stringstream aux(campo);

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
    */
    return true;
}

//Imprime na tela o cabaçalho da tabela com os dados
void Pessoa::imprimeCabecalho(){
    cout<<setfill('-')<<setw(82)<<'-'<<endl;
    cout<<"| "<<"CODIGO"<<setfill(' ')<<setw(4);
    /*cout<<"| "<<"NOME"<<setfill(' ')<<setw(21);
    cout<<" | "<<"SOBRENOME"<<setfill(' ')<<setw(6);
    cout<<" | "<<"TELEFONE"<<setfill(' ')<<setw(10);
    cout<<" | "<<"DT NASC"<<setfill(' ')<<setw(6)<<" | "<<endl;
    */cout<<endl<<setfill('-')<<setw(82)<<'-'<<endl;
}
//Imprime na tela os dados organizados em tabela
void Pessoa::mostraTela(){

    /*
    stringstream codigoStream;
    codigoStream << codigo;
    cout<<"| "<<codigoStream.str()<<setw(10 - codigoStream.str().length())<<setfill(' ')<<" | ";
    cout<<"| "<<nome<<setw(25 - nome.length())<<setfill(' ')<<" | ";
    cout<<sobrenome<<setfill(' ')<<setw(15 - sobrenome.length())<<" | ";
    cout<<telefone<<" | ";
    stringstream aux;
    aux<<setfill('0')<<setw(2)<<novaData.getDia()<<"/"<<setw(2)<<novaData.getMes()<<"/"<<setw(4)<<novaData.getAno()<<" | "<<offset;
    cout<<aux.str()<<endl;*/
    cout<<offset<<endl;
    cout<<setfill('-')<<setw(82)<<'-'<<endl;
}
//Função ordena lista
void Pessoa::ordenaLista(){
    listaDeRegistros.sort();
}
//Imprime Lista
void Pessoa::imprimeLista(){
    list<vector<int>>::iterator it;

    for(it = listaDeRegistros.begin(); it!=listaDeRegistros.end(); ++it){
        stringstream codigoStream;
        codigoStream<<"| "<< (*it)[0]<<" | "<<(*it)[1]<<endl;
        cout<<codigoStream.str();
    }
}
//Salva Indexes
void Pessoa::salvaIndex(fstream &arqOut){

    list<vector<int>>::iterator it;
    int aux;
    for(it = listaDeRegistros.begin(); it!=listaDeRegistros.end(); ++it){
        aux = (*it)[0];
        arqOut.write(reinterpret_cast<const char*>(&aux), sizeof(int));
        aux = (*it)[1];
        arqOut.write(reinterpret_cast<const char*>(&aux), sizeof(int));
    }

}
//Salva registros ordenados em arquivo de saída
void Pessoa::registrosOrdenados(ifstream &arqIn, fstream &index, fstream &arqOut){
    int auxCod, auxOff, dia, mes, ano;
    short tamanho;
    char campo[100], diaAux[10], mesAux[10], anoAux[10];
    
    while(index.good() && arqIn.good()){
        stringstream tratamento, aux;
        index.read(reinterpret_cast<char*>(&auxCod), sizeof(int));
        index.read(reinterpret_cast<char*>(&auxOff), sizeof(int));

        arqIn.seekg(auxOff);
        
        arqIn.read(reinterpret_cast<char*>(&tamanho), sizeof(short));
        
        arqIn.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        arqIn.read(campo,tamanho-sizeof(int));

        arqOut.write(reinterpret_cast<const char*>(&tamanho), sizeof(short));
        arqOut.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
        tratamento<<campo;
        getline(tratamento,nome,'|');
        getline(tratamento,nome,'|');
        getline(tratamento,sobrenome,'|');
        getline(tratamento,telefone,'|');
        tratamento.getline(diaAux,3,'/');
        tratamento.getline(mesAux,3,'/');
        tratamento.getline(anoAux,5,'&');

        dia = atoi(diaAux);
        mes = atoi(mesAux);
        ano = atoi(anoAux);

        novaData.setDataNascimento(dia, mes, ano);

        aux<<"|"<<nome<<"|"<<sobrenome<<"|"<<telefone<<"|"<<getDataNascimento();

        arqOut.write(aux.str().c_str(),aux.str().length());
        cout<<codigo<<aux.str()<<endl;

    }


}