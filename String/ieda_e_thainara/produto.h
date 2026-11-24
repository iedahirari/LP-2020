#pragma once
#include "cadastro.h"

inline int produtomenu() {
    int opcao;
    while (true) {
        std::cout << "Produto" << std::endl;
        std::cout << CADASTRAR_v1 << " - Incluir" << std::endl;
        std::cout << LISTAR_v1 << " - Listar" << std::endl;
        std::cout << PESQUISAR_v1 << " - Pesquisar" << std::endl;
        std::cout << ALTERAR_v1 << " - Alterar" << std::endl;
        std::cout << EXCLUIR_v1 << " - Excluir" << std::endl;
        std::cout << "6 - Voltar" << std::endl;
        if (!lerInteiro(opcao) || opcao == 6) return 0;
        switch (opcao) {
        case CADASTRAR_v1: cadastrar(produtov, Pos_produto); break;
        case LISTAR_v1: listarTexto(0, produtov, Pos_produto); break;
        case PESQUISAR_v1: pesquisar(0, produtov, Pos_produto); break;
        case ALTERAR_v1: alterar(0, produtov, Pos_produto); break;
        case EXCLUIR_v1: excluir(0, produtov, Pos_produto); break;
        default: std::cout << "Opcao invalida." << std::endl;
        }
    }
}
