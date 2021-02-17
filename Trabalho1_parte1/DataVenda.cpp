#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <type_traits>
#include "DataVenda.h"
using namespace std;

//Constantes para teste de validade da data
const int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define BISSEXTO(ano) (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))

DataVenda::DataVenda()
{
  dia = mes = ano = hora = minuto = 1;
}

DataVenda::DataVenda(int dia, int mes, int ano, int hora, int minuto)
{
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
  this->hora = hora;
  this->minuto = minuto;
}

bool DataVenda::DataValida(int dia, int mes, int ano, int hora, int minuto)
{
  if (ano > 0 && mes > 0 && mes <= 12 && dia > 0 && hora >= 0 && hora < 24 && minuto >= 0 && minuto < 60)
  {
    if (BISSEXTO(ano) && mes == 2)
    {
      return (dia <= 29);
    }

    return (dia <= dias[mes - 1]);
  }
  return false;
}

bool DataVenda::setDataVenda(int dia, int mes, int ano, int hora, int minuto)
{
  if (DataValida(dia, mes, ano, hora, minuto))
  {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;

    this->hora = hora;
    this->minuto = minuto;

    return true;
  }
  return false;
}

string DataVenda::getDataVenda()
{
  stringstream aux;
  aux << setfill('0') << setw(2) << dia << "/" << setw(2) << mes << "/" << setw(4) << ano << " " << setw(2) << hora << ":" << setw(2) << minuto;
  return aux.str();
}

string DataVenda::getDataToCompare()
{
  stringstream aux;
  aux << setfill('0') << setw(4) << ano << setw(2) << mes << setw(2) << dia;
  return aux.str();
}

int DataVenda::getDia() { return dia; }

int DataVenda::getMes() { return mes; }

int DataVenda::getAno() { return ano; }

int DataVenda::getHora() { return hora; }

int DataVenda::getMinuto() { return minuto; }