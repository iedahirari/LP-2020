# LP-2020 — exercícios de C++

Exercícios de programação em C++ com menus de console, vetores, matrizes de caracteres e recursão. Os exemplos trabalham com cadastros de produtos, caminhões, clientes e veículos.

Cada pasta representa uma etapa independente dos estudos. Não há banco de dados nem dependências externas de bibliotecas: os registros ficam em memória e são descartados quando o programa é encerrado.

## Organização

| Pasta ou arquivo | Conteúdo |
| --- | --- |
| [Vetores Parte 01](<Vetores Parte 01>) | Cadastro, consulta, alteração e exclusão de caracteres em três vetores independentes. |
| [String](String) | Cadastro, listagem, pesquisa por texto, alteração e exclusão em matrizes de caracteres. |
| [Consolidação dos Conteúdos](<Consolidação dos Conteúdos>) | Cadastro e pesquisa de veículos, quilometragem e listagem de revisões. |
| [entrada.h](entrada.h) | Leitura e validação de números inteiros e textos, compartilhadas pelos exercícios. |
| [CMakeLists.txt](CMakeLists.txt) | Compilação dos três programas a partir da raiz do repositório. |
| [tests/test_programas.py](tests/test_programas.py) | Testes automatizados dos programas pelo terminal. |

Os diretórios de Vetores e String também mantêm suas soluções do Visual Studio. A estrutura dos exercícios, os vetores de tamanho fixo e as operações recursivas foram preservados.

## Requisitos

- Um compilador C++ com suporte a C++11 ou superior.
- CMake 3.16 ou superior para usar a compilação unificada.
- Python 3.8 ou superior, apenas para os testes automatizados.

No Windows, instale o Visual Studio com a carga de trabalho **Desenvolvimento para desktop com C++**, incluindo compilador, Windows SDK e ferramentas CMake. Execute os comandos em um terminal no qual o CMake esteja disponível, como o **Developer PowerShell for Visual Studio**.

## Baixar e compilar

```sh
git clone https://github.com/iedahirari/LP-2020.git
cd LP-2020
cmake -S . -B build
cmake --build build --config Debug
```

A compilação gera três executáveis: `vetores`, `strings` e `consolidacao`.

### Executar no Windows com o gerador Visual Studio

No PowerShell, escolha um dos programas:

```powershell
.\build\Debug\vetores.exe
.\build\Debug\strings.exe
.\build\Debug\consolidacao.exe
```

### Executar com um gerador de configuração única

Com Makefiles ou Ninja, os executáveis normalmente ficam diretamente em `build`. Em Linux ou macOS:

```sh
./build/vetores
./build/strings
./build/consolidacao
```

O caminho de saída depende do gerador escolhido pelo CMake. A validação desta atualização foi feita no Windows com MSVC; os comandos para outros sistemas não foram executados.

### Abrir as soluções existentes

Você também pode abrir `Vetores Parte 01/ieda_e_thainara.sln` ou `String/ieda_e_thainara.sln` no Visual Studio e compilar o projeto.

Os arquivos de projeto usam o toolset padrão da instalação e o Windows SDK 10, em vez de exigir o antigo toolset v140 e o SDK 8.1. A compilação por CMake inclui ainda o exercício de consolidação.

## Como usar os menus

Digite cada opção ou valor em uma linha e pressione Enter. Entradas numéricas inválidas são rejeitadas e solicitadas novamente. Uma opção inexistente volta ao menu; o fim da entrada também encerra os programas.

### Vetores Parte 01

No menu principal:

- `1`: produto;
- `2`: caminhão;
- `3`: cliente;
- `4`: sair.

Dentro de cada categoria:

| Opção | Operação |
| --- | --- |
| 1 | Incluir um caractere. |
| 2 | Consultar os registros e suas posições. |
| 3 | Alterar um registro pela posição. |
| 4 | Excluir um registro pela posição. |
| 5 | Voltar ao menu principal. |

Neste exercício, a opção **Pesquisar** mostra o conteúdo do vetor. Os índices começam em **zero**. Cada categoria aceita até **10 registros**, e cada registro é um caractere de um byte.

### String

O menu principal tem as mesmas categorias e a opção `4` para sair. Os submenus oferecem:

| Opção | Operação |
| --- | --- |
| 1 | Incluir um texto. |
| 2 | Listar os textos e suas posições. |
| 3 | Pesquisar um texto completo. |
| 4 | Alterar pela posição. |
| 5 | Excluir pela posição. |
| 6 | Voltar ao menu principal. |

Cada categoria aceita até **10 textos**. Cada texto pode ocupar até **9 bytes**, pois a última posição da linha da matriz é reservada ao terminador nulo.

A pesquisa exige igualdade exata, diferencia maiúsculas de minúsculas e retorna a primeira ocorrência. Espaços no meio do nome são permitidos. Textos vazios, compostos apenas de espaços ou maiores que o limite são rejeitados.

### Consolidação dos Conteúdos

| Opção | Operação |
| --- | --- |
| 1 | Cadastrar um veículo e sua quilometragem desde a última revisão. |
| 2 | Listar os veículos com a quilometragem informada. |
| 3 | Pesquisar um veículo pelo nome completo. |
| 4 | Listar os veículos com revisão pendente no exercício. |
| 9 | Sair. |

São permitidos até **10 veículos**, com nomes de até **19 bytes** e quilometragem inteira não negativa. O critério implementado pelo exercício é **1.500 km ou mais** desde a última revisão. A listagem percorre todos os veículos, mesmo quando os primeiros ainda estão abaixo desse limite.

## Testes automatizados

Depois da compilação com Visual Studio:

```sh
python tests/test_programas.py build/Debug
```

Para geradores que colocam os executáveis diretamente em `build`:

```sh
python tests/test_programas.py build
```

Os testes usam apenas a biblioteca padrão do Python e executam os programas com entradas simuladas. Eles verificam:

- saída dos menus e encerramento por fim da entrada;
- recuperação de números inválidos;
- separação dos cadastros de produto, caminhão e cliente;
- alteração, exclusão e reorganização dos registros;
- rejeição de posições inválidas, cadastro cheio e textos fora do limite;
- pesquisa de textos;
- listagem de revisões abaixo, no limite e acima de 1.500 km.

Na validação de **24/11/2026**, os três programas compilaram com CMake e MSVC, as duas soluções existentes compilaram em Debug/x64 e as **25 execuções de teste passaram**.

## Correções realizadas

- Corrigido o nome do cabeçalho incluído pelo exercício de consolidação.
- Corrigidos os menus que não encerravam ou exibiam a mesma opção para excluir e sair.
- Separados os vetores de clientes e produtos e corrigidas as operações de texto que usavam vetores de caracteres avulsos.
- Adicionadas validações de capacidade, tamanho de texto e posição antes de acessar os vetores.
- Corrigida a exclusão de registros e a reorganização dos elementos.
- Substituída a comparação inválida entre o nome do veículo e um número por um campo de quilometragem.
- Removidos `system("pause")` e os arquivos `Source.cpp` sem uso nos projetos.
- Retirados do versionamento executáveis, arquivos de depuração e caches do Visual Studio; esses arquivos passam a ser ignorados pelo Git.

## Limites dos exemplos

Os dados não são gravados em arquivo. Os limites de texto são medidos em **bytes**, não em letras: caracteres acentuados em UTF-8 podem ocupar mais de um byte. As mensagens dos programas usam texto sem acentos para facilitar o uso em diferentes terminais.

Não compile todos os arquivos `.cpp` do repositório em um único executável: cada exercício possui seu próprio `main`. Use os alvos separados do CMake ou abra uma das soluções do Visual Studio.
