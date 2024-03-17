# Computação Gráfica II (CK0246)

Código dos projetos desenvolvidos para a disciplina de Computação Gráfica II (CK0246) da UFC.

## Dependências

O projeto utiliza a API gráfica [OpenGL](https://www.opengl.org/) e depende das bibliotecas [FreeGLUT](https://freeglut.sourceforge.net/) e [GLEW](https://glew.sourceforge.net/). Também é necessário utilizar alguma distribuição Linux como sistema operacional e ter o programa [make](https://www.gnu.org/software/make/) instalado para compilar o código.
Também são utilizados os headers disponibilizados no repositório [cyCodeBase](https://github.com/cemyuksel/cyCodeBase/).

## Build

Para compilar o código, basta utilizar o comando **make** na raíz do projeto indicando o arquivo que contém a função main, como a seguir:
```console
make MAIN="src/arquivo.cpp"
```
Se não for indicado o arquivo com a função main, o make irá procurar pelo arquivo padrão "src/main.cpp".

**Obs.:** O arquivo contendo a função main **deve** estar dentro da pasta "src/".

## Executando

Para executar o código compilado, basta executar o seguinte comando na raíz do projeto:
```console
./main
```