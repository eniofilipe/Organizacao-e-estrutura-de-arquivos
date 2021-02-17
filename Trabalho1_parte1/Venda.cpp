#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <type_traits>

using namespace std;
#include "Venda.h"

//constructors
Venda::Venda()
{
  nome = "";
  produto = "";
  meio_pagamento = "";
  cidade = "";
  pais = "";
  estado = "";

  preco = 0;

  novaData.setDataVenda(1, 1, 1, 1, 1);
}

//Construtor cheio
Venda::Venda(string nome,
             string produto,
             string meio_pagamento,
             string cidade,
             string estado,
             string pais,
             int dia,
             int mes,
             int ano,
             int hora,
             int minuto,
             float preco)
{

  this->nome = nome;
  this->produto = produto;
  this->meio_pagamento = meio_pagamento;
  this->cidade = cidade;
  this->estado = estado;
  this->pais = pais;
  this->preco = preco;

  novaData.setDataVenda(dia, mes, ano, hora, minuto);
}

//setters
void Venda::setNome(string nome)
{
  this->nome = nome;
}
void Venda::setProduto(string produto)
{
  this->produto = produto;
}
void Venda::setMeioPagamento(string meio_pagamento)
{
  this->meio_pagamento = meio_pagamento;
}
void Venda::setCidade(string cidade)
{
  this->cidade = cidade;
};
void Venda::setEstado(string estado)
{
  this->estado = estado;
};
void Venda::setPais(string pais)
{
  this->pais = pais;
};
bool Venda::setDataVenda(int dia, int mes, int ano, int hora, int minuto)
{
  return novaData.setDataVenda(dia, mes, ano, hora, minuto);
}
void Venda::setPreco(float preco)
{
  this->preco = preco;
};

//getters
string Venda::getNome()
{
  return nome;
}
string Venda::getProduto()
{
  return produto;
};
string Venda::getMeioPagamento()
{
  return meio_pagamento;
};
string Venda::getCidade()
{
  return cidade;
};
string Venda::getEstado()
{
  return estado;
};
string Venda::getPais()
{
  return pais;
};
DataVenda Venda::getDataVenda()
{
  return novaData;
};
float Venda::getPreco()
{
  return preco;
};

//Faz a leitura do dado no arquivo de entrada
bool Venda::lerVenda(fstream &arqIn)
{

  //verifica se o arquivo de entrada é válido
  if (!arqIn.good())
    return false;

  char campo[100];
  int dia, mes, ano, hora, minuto;

  //Lê uma cadeia de caracteres de certo tamanho no arquivo até um delimitador getline(char*[], tamanho, delimitador)
  arqIn.getline(campo, 3, '/');
  dia = atoi(campo);

  arqIn.getline(campo, 3, '/');
  mes = atoi(campo);

  arqIn.getline(campo, 5, ' ');
  ano = atoi(campo);

  arqIn.getline(campo, 3, ':');
  hora = atoi(campo);

  arqIn.getline(campo, 3, ';');
  minuto = atoi(campo);

  arqIn.getline(campo, 100, ';');
  produto = campo;

  arqIn.getline(campo, 100, ';');
  preco = atoi(campo);

  arqIn.getline(campo, 100, ';');
  meio_pagamento = campo;

  arqIn.getline(campo, 100, ';');
  nome = campo;

  arqIn.getline(campo, 100, ';');
  cidade = campo;

  arqIn.getline(campo, 100, ';');
  estado = campo;

  arqIn.getline(campo, 100, '\n');
  pais = campo;

  novaData.setDataVenda(dia, mes, ano, hora, minuto);
  return true;
}

// Mostra os dados na tela
void Venda::mostraTela()
{
  cout << "Data/hora da venda: " << getDataVenda().getDataVenda() << endl;
  cout << "Produto: " << produto << endl;
  cout << "Preco: " << preco << endl;
  cout << "Meio de pagamento: " << meio_pagamento << endl;
  cout << "Nome: " << nome << endl;
  cout << "Cidade: " << cidade << endl;
  cout << "Estado: " << estado << endl;
  cout << "Pais: " << pais << endl;
  /* stringstream aux;
  aux << setfill('0') << setw(2) << novaData.getDia() << "/" << setw(2) << novaData.getMes() << "/" << setw(4) << novaData.getAno();
  cout << "Data de nascimento: " << aux.str() << endl; */
}
