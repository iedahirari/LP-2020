#pragma once
#include <iostream>
#include "constante.h"
#include <stdio.h>
using namespace std;

void cadastrar(char vRecebido[TAMANHO], int indicePosicao) {
	cout << "Cadastrar" << endl;
	cout << "entre com o valor a ser cadastrado:" << endl;
	int posicaoIncluir = pos[indicePosicao];
	cin >> vRecebido[posicaoIncluir];
	pos[indicePosicao]++;
}

void pesquisar(int i, char vRecebido[TAMANHO], int indicePosicao) {
	if (i == pos[indicePosicao]) {
		return;
	}
	cout << "valor Posição:" << i << "-" << vRecebido[i] << endl;
	pesquisar(i + 1, vRecebido, indicePosicao);
}

void alterar(int i, char vRecebido[TAMANHO], int indicePosicao) {
	cout << "alterar" << endl;
	cout << "Entre com a posição a ser alterada" << endl;
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
	cout << "Entre com a posição a ser excluida" << endl;
	pesquisar(0, vRecebido, indicePosicao);
	int p = 0;
	cin >> p;
	reorganizar(p, vRecebido, indicePosicao);
	pos[indicePosicao]--;
	vRecebido[pos[indicePosicao]] = 0;
}
