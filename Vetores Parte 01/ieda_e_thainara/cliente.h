#pragma once
#include "stdafx.h"
#include <iostream>
#include "cadastro.h"
#include "constante.h"

using namespace std;

int clientemenu()

{
	int opcao = 0;
	do {
		cout << "Cliente" << endl;
		cout << CADASTRAR_v3 << " - Incluir" << endl;
		cout << PESQUISAR_v3 << " - Pesquisar" << endl;
		cout << ALTERAR_v3 << " - Alterar" << endl;
		cout << EXCLUIR_v3 << " - Excluir" << endl;
		cout << "5 - Sair" << endl;
		cout << "Entre com Opcao" << endl;
		cin >> opcao;
		switch (opcao){
		
		case CADASTRAR_v3: cadastrar(vetor1, IndiceVetor3);break;
		case PESQUISAR_v3: pesquisar(0, vetor1, IndiceVetor3);break;
		case ALTERAR_v3: alterar(0, vetor1, IndiceVetor3);break;
		case EXCLUIR_v3: excluir(0, vetor1, IndiceVetor3);break;
		default:
			break;
		}
	} while (opcao >= 1 && opcao <= 5);

	system("pause");
	return 0;
}