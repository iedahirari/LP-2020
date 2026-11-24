#include "constante.h"
#include "produto.h"

int main() {
    int opcao;
    while (true) {
        std::cout << "Sistema\n1 - Cadastrar veiculo\n2 - Listar veiculos\n"
                     "3 - Pesquisar veiculo\n4 - Listar revisoes\n9 - Sair" << std::endl;
        if (!lerInteiro(opcao) || opcao == SAIR) return 0;
        switch (opcao) {
        case CADASTRAR: cadastrarTexto(produto, posProduto); break;
        case LISTAR: listarTexto(0, produto, posProduto); break;
        case PESQUISAR: {
            std::cout << "Entre com o veiculo a ser pesquisado:" << std::endl;
            std::string nome;
            if (lerTexto(nome, LARGURA - 1))
                pesquisarTexto(0, produto, posProduto, nome);
            break;
        }
        case LISTAR3: listarRevisao(0, produto, posProduto); break;
        default: std::cout << "Opcao invalida." << std::endl;
        }
    }
}
