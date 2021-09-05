#pragma once
#include "constante.h"
#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

void cadastrar(char v[TAMANHO][LARGURA], int indice) {
	cout << "Cadastrar" << endl;
	cout << "entre com o valor a ser cadastrado:" << endl;
	int posicaoCadastro = cadastrados[indice];	
	string nome1;
	cin.ignore();
	getline(cin, nome1);
	strcpy_s(v[posicaoCadastro], nome1.c_str());
	cadastrados[indice]++;
}

void listarTexto(int i, char v[TAMANHO][LARGURA], int indice) {
	if (i == cadastrados[indice]) {
		return;
	}
	cout << "Valor posicao: " << i << "-" << v[i] << endl;
	listarTexto(i + 1, v, indice);
}

void pesquisar(int i, char vRecebido[TAMANHO], int indicePosicao) {
	if (i == pos[indicePosicao]) {
		return;
	}
	cout << "valor Posicao:" << i << "-" << vRecebido[i] << endl;
	pesquisar(i + 1, vRecebido, indicePosicao);
}

void alterar(int i, char vRecebido[TAMANHO], int indicePosicao) {
	cout << "alterar" << endl;
	cout << "Entre com a posicao a ser alterada" << endl;
	pesquisar(0, vRecebido, indicePosicao);
	int p = 0;
	cin >> p;
	cout << "digite o valor";
	cin >> vRecebido[p];
}
void reorganizar(int i, char vRecebido[TAMANHO], int indicePosicao) {
	if (i == (pos[indicePosicao] - 1)) {
		return;
	}
	vRecebido[i] = vRecebido[i + 1];
	reorganizar(i + 1, vRecebido, indicePosicao);
}
void excluir(int i, char vRecebido[TAMANHO], int indicePosicao) {
	cout << "excluir" << endl;
	cout << "Entre com a posica9o a ser excluida" << endl;
	pesquisar(0, vRecebido, indicePosicao);
	int p = 0;
	cin >> p;
	reorganizar(p, vRecebido, indicePosicao);
	pos[indicePosicao]--;
	vRecebido[pos[indicePosicao]] = 0;
}
