#pragma once
#include "cadastro.h"

inline int clientemenu() {
    int opcao;
    while (true) {
        std::cout << "Cliente" << std::endl;
        std::cout << CADASTRAR_v3 << " - Incluir" << std::endl;
        std::cout << LISTAR_v3 << " - Listar" << std::endl;
        std::cout << PESQUISAR_v3 << " - Pesquisar" << std::endl;
        std::cout << ALTERAR_v3 << " - Alterar" << std::endl;
        std::cout << EXCLUIR_v3 << " - Excluir" << std::endl;
        std::cout << "6 - Voltar" << std::endl;
        if (!lerInteiro(opcao) || opcao == 6) return 0;
        switch (opcao) {
        case CADASTRAR_v3: cadastrar(clientev, Pos_cliente); break;
        case LISTAR_v3: listarTexto(0, clientev, Pos_cliente); break;
        case PESQUISAR_v3: pesquisar(0, clientev, Pos_cliente); break;
        case ALTERAR_v3: alterar(0, clientev, Pos_cliente); break;
        case EXCLUIR_v3: excluir(0, clientev, Pos_cliente); break;
        default: std::cout << "Opcao invalida." << std::endl;
        }
    }
}
