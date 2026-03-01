Sobre o projeto
===

Aplicação C++ com Slint de uma simples calculadora com as operações básicas: +, -, *, /, ^ (potência x em y), ^2 (x ao quadrado), raiz quadrada, raiz y de x, e com botão para constante PI e para constante euler. Usando arquitetura MVVM para separação das partes: View, Model e ViewModel. O projeto usa CMake para construção (build) de código, verificação de dependência (use o mínimo possível).

A aplicação foi criada com intuito de aplicar e praticar uso de IAs com agente `Claude CLI` para geração de códigos usando modelos de IA gratuitos rodando de forma Local com a aplicação `Ollama`.

Os modelos testados foram:

* gpt-oss:20b: Melhor resultado no geral.
* qween-code:30b: Funciona, mas é inviável no meu ambiente com apenas 16GB de VRAM (Memória de vídeo em GPU)
* glm-4.7-flash:q8_0: Inviável por uso extensivo de RAM que torna tudo mas lento. O ideal seria ter ao menos 32G de VRAM.
* lfm2:24b: Resultados aceitáveis, mas ainda demora bastante, mesmo sendo um modelo de apenas 14GB.
* Outros: foram testados modelos com 23GB ou mais, porém é impraticável para máquinas com pouca memória de vídeo disponível.

Resultados
---

Boa parte do projeto foi gerada com ajuda de modelos de IA rodando localmente por meio da CLI Claude.

Os modelos, nesta configuração, demoram muito para realizar mesmo tarefas simples. Um pedido de análise da estrutura do projeto para adição da integração do MVVM entre ViewModel e View auto gerada pelo Slint, levou mais de 2 horas e 40 minutos, sem sucesso, tendo sido realizada manualmente, com ajuda de IA cloud `Gemini` da `Google`.

Testes foram adicionados com ajuda do modelo `gpt-oss:20b` via `Claude CLI``, mas precisaram de vários ajustes nos arquivos de `CMakeLists.txt` até ficarem funcionais. Aliás, as configurações foram colocadas juntas do arquivo `CMakeLists.txt` da raiz do projeto e foram movidas e adaptadas para arquivo próprio na pasta de testes: `tests`.

Build da Aplicação
---

É preciso ter instalado e configurado o vcpkg. Veja instruções em: [Guia geral Vcpkg com CMake](https://learn.microsoft.com/pt-br/vcpkg/get_started/get-started?pivots=shell-bash).

Esta aplicação não foi testada em Windows ou Mac, mas deve ser facilmente portada para estes SOs com nenhum ou pequenos ajustes.

### Pré requisitos
1. Git instalado e configurado.
2. Variáveis de ambiente do VCPKG configuradas conforme indicado no `Guia geral Vcpkg com Cmake` acima.
3. CMake na versão 4.2 ou superior.
4. Ninja como builder, de preferência
5. Compilador Clang C++ ou G++ com suporte a C++23.

Os comandos abaixo são todos executados a partir da raiz do projeto.

### Configurando o Build
```sh
cmake -B build
```

Se desejar usar o preset `default`, configurar o VCPKG_ROOT no arquivo `CMakePrests.json` de acordo com o local de instalação do `Vcpkg`.

### Rodando build com preset
```sh
cmake --preset default
```

### Construindo o projeto
```sh
cmake --build build --target calculator_slint_app
```

### Executando o projeto gerado
```sh
./build/src/calculator_slint_app
```

### Construindo os tests
```sh
cmake --build build --target calculator_slint_tests
```

### Executando os tests
```sh
cd build/tests
ctest # para rodar todos os testes
```
