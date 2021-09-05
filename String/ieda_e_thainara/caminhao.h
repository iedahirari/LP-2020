#pragma once
#include "stdafx.h"
#include <iostream>
#include "cadastro.h"
#include "constante.h"

using namespace std;

int caminhaomenu()

{
	int opcao = 0;
	do {
		cout << "Caminhao" << endl;

		cout << CADASTRAR_v2 << " - Incluir" << endl;
		cout << LISTAR_v2 << "- Listar" << endl;
		cout << PESQUISAR_v2 << " - Pesquisar" << endl;
		cout << ALTERAR_v2 << " - Alterar" << endl;
		cout << EXCLUIR_v2 << " - Excluir" << endl;
		cout << "6 - Sair" << endl;
		cout << "Entre com Opcao" << endl;
		cin >> opcao;
		switch (opcao)
		{
		case CADASTRAR_v2: cadastrar(caminhaov, Pos_caminhao);break;
		case LISTAR_v2: listarTexto(0, caminhaov, Pos_caminhao);break;
		case PESQUISAR_v2: pesquisar(0, vetor2, IndiceVetor2);break;
		case ALTERAR_v2: alterar(0, vetor2, IndiceVetor2);break;
		case EXCLUIR_v2: excluir(0, vetor2, IndiceVetor2);break;
		default:
			break;
		}
	} while (opcao >= 1 && opcao <= 6);

	system("pause");
	return 0;
}
