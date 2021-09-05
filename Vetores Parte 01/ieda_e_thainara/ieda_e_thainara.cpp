#include "stdafx.h"
#include <iostream>
#include "constante.h"
#include "produto.h"
#include "caminhao.h"
#include "cliente.h"

using namespace std;

int main()
{
	int opcao;
	do {
		cout << "Menu" << endl;
		cout << produto << " - Produto" << endl;
		cout << caminhao << "- Caminhao" << endl;
		cout << cliente << " - Cliente" << endl;
		cout << "4 - Sair" << endl;
		cout << "Entre com Opcao" << endl;
		cin >> opcao;
		switch (opcao)
		{
		case produto: produtomenu();break;
		case caminhao: caminhaomenu();break;
		case cliente: clientemenu();break;
		
		default:
			break;
		}
	} while (opcao >= 1 && opcao <= 4);
	system("pause");
	return 0;
}
