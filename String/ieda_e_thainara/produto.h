#pragma once
#include "stdafx.h"
#include <iostream>
#include "cadastro.h"
#include "constante.h"

using namespace std;

int produtomenu()

{
	int opcao=0;
	do {
		cout << "Produto" << endl;
		
		cout << CADASTRAR_v1 << " - Incluir" << endl;
		cout << LISTAR_v1 << "- Listar" << endl;
		cout << PESQUISAR_v1 << " - Pesquisar" << endl;
		cout << ALTERAR_v1 << " - Alterar" << endl;
		cout << EXCLUIR_v1 << " - Excluir" << endl;
		cout << "5 - Sair" << endl;
		cout << "Entre com Opcao" << endl;
		cin >> opcao;
		switch (opcao)
		{
		case CADASTRAR_v1: cadastrar(produtov, Pos_produto);break;
		case LISTAR_v1:    listarTexto(0, produtov, Pos_produto);break;
		case PESQUISAR_v1: pesquisar(0, vetor1, IndiceVetor1);break;
		case ALTERAR_v1:   alterar(0, vetor1, IndiceVetor1);break;
		case EXCLUIR_v1:   excluir(0, vetor1, IndiceVetor1);break;
		default:
			break;
		}
	} while (opcao >= 1 && opcao <= 5);

	system("pause");
	return 0;
}