#ifndef VENDA_H_
#define VENDA_H_
#endif

#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include "DataVenda.h"

using namespace std;

class Venda
{

private:
  std::string nome, produto, meio_pagamento, cidade, estado, pais;
  DataVenda novaData;
  float preco;

public:
  ///constructor
  Venda();
  Venda(
      std::string nome,
      std::string produto,
      std::string meio_pagamento,
      std::string cidade,
      std::string estado,
      std::string pais,
      int dia,
      int mes,
      int ano,
      int hora,
      int minuto,
      float preco);

  //setters
  void setNome(std::string nome);
  void setProduto(std::string produto);
  void setMeioPagamento(std::string meio_pagamento);
  void setCidade(std::string cidade);
  void setEstado(std::string estado);
  void setPais(std::string pais);
  void setPreco(float preco);
  bool setDataVenda(int dia, int mes, int ano, int hora, int minuto);

  //getters
  std::string getNome();
  std::string getProduto();
  std::string getMeioPagamento();
  std::string getCidade();
  std::string getEstado();
  std::string getPais();
  DataVenda getDataVenda();
  float getPreco();

  ///Mostrar na tela
  void mostraTela();

  //Ler do Arquivo
  bool lerVenda(fstream &arqIn);
};
