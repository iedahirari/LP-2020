#include "stdafx.h"
#include "produto.h"
#include "caminhao.h"
#include "cliente.h"

int main() {
    int opcao;
    while (true) {
        std::cout << "Menu\n1 - Produto\n2 - Caminhao\n3 - Cliente\n4 - Sair" << std::endl;
        if (!lerInteiro(opcao) || opcao == 4) return 0;
        switch (opcao) {
        case produto: produtomenu(); break;
        case caminhao: caminhaomenu(); break;
        case cliente: clientemenu(); break;
        default: std::cout << "Opcao invalida." << std::endl;
        }
    }
}
