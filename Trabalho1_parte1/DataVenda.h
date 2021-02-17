#ifndef DATAVENDA_H_
#define DATAVENDA_H_
#endif

#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class DataVenda
{

private:
  int dia, mes, ano, hora, minuto;
  bool DataValida(int dia, int mes, int ano, int hora, int minuto);

public:
  DataVenda();
  DataVenda(int dia, int mes, int ano, int hora, int minuto);

  bool setDataVenda(int dia, int mes, int ano, int hora, int minuto);

  std::string getDataVenda();
  int getDia();
  int getMes();
  int getAno();
  int getHora();
  int getMinuto();
  std::string getDataToCompare();
};