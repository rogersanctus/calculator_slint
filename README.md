Sobre o projeto
===

Aplicação C++ com Slint de uma simples calculadora com as operações básicas: +, -, *, /, ^ (potência x em y), ^2 (x ao quadrado), rais quadrada, rais y de x, e com botão para constante PI e para constante euler. Use arquitetura MVVM para separação das partes: View, Model e ViewModel. O projeto deve usar CMake para construção (build) de código, verificação de dependência (use o mínimo possível).
Cada coisa deve ter seu módulo no par: `modulo.h` e `modulo.cpp` e deve haver um arquivo main.cpp como entrypoint da aplicação. Siga as recomendações do projeto Slint. O C++ deve usar a versão C++23 e todas as boas práticas, evitando variáveis sem uso, ponteiros implícitos, etc.

Resultados
---

Boa parte do projeto foi gerada com ajuda de modelos de IA rodando localmente por meio da CLI Claude.

Os modelos, nesta configuração, demoram muito para realizar mesmo tarefas simples. Um pedido de análise da estrutura do projeto para adição da integração do MVVM entre ViewModel e View auto gerada pelo Slint, levou mais de 2 horas e 40 minutos, sem sucesso, tendo sido realizada manualmente, com ajuda de IA cloud `Gemini` da `Google`.

Testes foram adicionados com ajuda do modelo `gpt-oss:20b` via `Claude CLI``, mas precisaram de vários ajustes nos arquivos de `CMakeLists.txt` até ficarem funcionais. Aliás, as configurações foram colocadas juntas do arquivo `CMakeLists.txt` da raiz do projeto e foram movidas e adaptadas para arquivo próprio na pasta de testes: `tests`.
