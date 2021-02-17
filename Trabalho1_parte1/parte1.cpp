/*
*****************************************************************
*  Trabalho Organização e Estrutura de Arquivos                 *
*  -- Trabalho 1 - parte 1.                                         *  
*  -- Ênio Filipe.                                *
*****************************************************************
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Venda.h"
#include <vector>

using namespace std;

void ShowAllOnScreen(vector<Venda> registros);

void SelectAction(int opcao, vector<Venda> registros);

int Menu();

void SearchForDate(vector<Venda> registros);

void SaveOnFile(vector<Venda> registros, std::string nomeArquivo);

int main()
{

  //Instância do novo objeto do tipo Venda
  Venda novaVenda;

  //Inicializa váriaveis dos arquivos de entrada e saída
  fstream arquivo;

  //Inicializa vetor de registros
  vector<Venda> registros;

  //Inicialização dos arquivos e teste de abertura do arquivo de entrada
  char linha[200];
  arquivo.open("entrada.txt", ios::in);
  /* novoArquivo.open("PessoasNovo.txt",ios::out); */
  arquivo.unsetf(ios::skipws);
  if (arquivo.good())
  {
    arquivo.getline(linha, 100, '\n');
    cout << linha << endl;
  }
  else
  {
    cout << "ERRO ao abrir arquivo!";
    exit(1);
  }

  //Realiza a leitura dos dados no arquivo de entrada e aloca no vetor
  while (novaVenda.lerVenda(arquivo))
  {
    registros.push_back(novaVenda);
  }

  int opcao = Menu();

  while (opcao != 0)
  {
    SelectAction(opcao, registros);

    opcao = Menu();
  }

  /* //Fecha arquivo de saída
    novoArquivo.close(); */

  exit(0);
}

int Menu()
{

#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  system("clear");
#endif

  int opcao;

  cout << "Menu -> Digite a opção requerida" << endl;
  cout << endl;
  cout << "1 - Pesquisa por data" << endl;
  cout << "2 - Imprimir tudo" << endl;
  cout << endl;
  cout << "0 - Sair" << endl;
  cout << "----------------------------------------------" << endl;

  cin >> opcao;

  return opcao;
}

void SelectAction(int opcao, vector<Venda> registros)
{

  switch (opcao)
  {
  case 1:
  {
    SearchForDate(registros);
    break;
  }
  case 2:
  {
    ShowAllOnScreen(registros);
    break;
  }
  default:
  {
    cout << "Opção inexistente!";
  }
  }
}

void ShowAllOnScreen(vector<Venda> registros)
{

  string aux;

  for (int i = 0; i < registros.size(); i++)
  {
    registros[i].mostraTela();
    cout << "--------------------" << endl;
  }

  std::cin.ignore();
  do
  {
    cout << '\n'
         << "Pressione ENTER para continuar...";
  } while (cin.get() != '\n');
}

void SearchForDate(vector<Venda> registros)
{
  int dayIn, dayEnd, monthIn, monthEnd, yearIn, yearEnd;
  stringstream dateIn, dateEnd;
  vector<Venda> searchRegisters;

  cout << "Entre com o dia da data incial" << endl;
  cin >> dayIn;
  cout << "Entre com o mês da data incial" << endl;
  cin >> monthIn;
  cout << "Entre com o ano da data incial" << endl;
  cin >> yearIn;

  cout << "Entre com o dia da data final" << endl;
  cin >> dayEnd;
  cout << "Entre com o mês da data final" << endl;
  cin >> monthEnd;
  cout << "Entre com o ano da data final" << endl;
  cin >> yearEnd;

  dateIn << setfill('0') << setw(4) << yearIn << setw(2) << monthIn << setw(2) << dayIn;
  dateEnd << setfill('0') << setw(4) << yearEnd << setw(2) << monthEnd << setw(2) << dayEnd;

  for (int i = 0; i < registros.size(); i++)
  {

    string aux = registros[i].getDataVenda().getDataToCompare();

    if (aux >= dateIn.str() && aux <= dateEnd.str())
    {
      searchRegisters.push_back(registros[i]);
    }
  }

  if (searchRegisters.size() == 0)
  {
    cout << "Não foi encontrado nenhum registro!" << endl;
  }
  else
  {

    for (int i = 0; i < searchRegisters.size(); i++)
    {

      searchRegisters[i].mostraTela();

      cout << "-------------------------------------------------------" << endl;
    }

    char op;

    do
    {
      cout << "Deseja gravar resultado em arquivo? (Digite S para sim e N para não)" << endl;
      cin >> op;

      if (op != 'S' && op != 's' && op != 'N' && op != 'n')
      {
        cout << "Opção errada" << endl;
      }
      else if (op == 'S' || op == 's')
      {

        stringstream aux;

        aux << dateIn.str() << "-" << dateEnd.str() << ".txt";

        SaveOnFile(searchRegisters, aux.str());
      }

    } while (op != 'S' && op != 's' && op != 'N' && op != 'n');
  }

  std::cin.ignore();
  do
  {
    cout << '\n'
         << "Pressione ENTER para continuar...";
  } while (cin.get() != '\n');
}

void SaveOnFile(vector<Venda> registros, std::string nomeArquivo)
{

  fstream novoArquivo;

  novoArquivo.open(nomeArquivo, ios::out);
  for (int i = 0; i < registros.size(); i++)
  {

    stringstream aux;

    aux << registros[i].getDataVenda().getDataVenda() << ";"
        << registros[i].getProduto() << ";"
        << registros[i].getPreco() << ";"
        << registros[i].getMeioPagamento() << ";"
        << registros[i].getNome() << ";"
        << registros[i].getCidade() << ";"
        << registros[i].getEstado() << ";"
        << registros[i].getPais() << "\n";

    short tam = aux.str().length();

    novoArquivo.write(aux.str().c_str(), tam);
  }

  cout << "Gravação finalizada";
}