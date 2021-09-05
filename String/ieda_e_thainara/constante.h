#pragma once
#define TAMANHO 10
#define LARGURA 10

#define produto 1
#define caminhao 2
#define cliente 3

#define CADASTRAR_v1 1
#define LISTAR_v1 2
#define PESQUISAR_v1 3
#define ALTERAR_v1 4
#define EXCLUIR_v1 5

#define CADASTRAR_v2 1
#define LISTAR_v2 2
#define PESQUISAR_v2 3
#define ALTERAR_v2 4
#define EXCLUIR_v2 5

#define CADASTRAR_v3 1
#define LISTAR_v3 2
#define PESQUISAR_v3 3
#define ALTERAR_v3 4
#define EXCLUIR_v3 5

#define Pos_vetor0 0
#define Pos_vetor1 1
#define Pos_produto 0
#define Pos_cliente 1
#define Pos_caminhao 2

#define IndiceVetor1 0
#define IndiceVetor2 1
#define IndiceVetor3 2

char vetor1[TAMANHO];
char vetor2[TAMANHO];
int posicao[3];
char produtov[TAMANHO][LARGURA];
char clientev[TAMANHO][LARGURA];
char caminhaov[TAMANHO][LARGURA];

int cadastrados[3];
int pos[3];





