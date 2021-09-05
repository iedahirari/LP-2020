#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

void cadastrarTexto(char v[TAMANHO][LARGURA], int Indice){
    cout << "Cadastrar" << endl;
    cout << "Entre com o veiculo a ser cadastrado" << endl;
    int posicaoCadastro = cadastrados[Indice];
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    
    strcpy(v[posicaoCadastro], nome1.c_str());
    cadastrados[Indice]++;
}

void listarTexto(int i, char v[TAMANHO][LARGURA], int Indice){
    if(i == cadastrados[Indice]){
        return;
    }
    cout << "Valor posição" << i << "-" << v[i] << endl;
    listarTexto(i + 1, v, Indice);
}

void pesquisarTexto(int i, char v[TAMANHO][LARGURA], int indice, char vetorPesquisa[LARGURA]) {
	if (i == cadastrados[indice]) {
	    cout << "Registro não encontrado" << endl;
		return;
	}
	int localizado = strcmp(v[i],vetorPesquisa);
	if(localizado==0) {
	    cout << v[i] << endl;
	    return;
	}else{
	    pesquisarTexto(i + 1, v, indice,vetorPesquisa);
	}
}

void listarRevisao(int i, char v[TAMANHO][LARGURA], int Indice){
    if(i == cadastrados[Indice]){
        return;
    }
    
    int revisao = 1500;
    
    if (v[i]>=revisao){
    cout << "Item" << i << " precisa de Revisão" << endl;
    listarTexto(i + 1, v, Indice);
    }else{
        return;
    }
}

