#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 5

// Definindo a estrutura da pilha
typedef struct {
    char livros[MAX_TAM][20]; // Array de strings para armazenar os livros
    int topo; // Índice do topo da pilha
} PilhaLivros;

// Função para inicializar a pilha
void inicializarPilha(PilhaLivros *pilha) {
    pilha->topo = -1; // Inicializa o topo como -1, indicando uma pilha vazia
}

// Função para empilhar um livro
void empilharLivro(PilhaLivros *pilha, char *livro) {
    if (pilha->topo == MAX_TAM - 1) { // Verifica se a pilha está cheia
        printf("Erro: Pilha cheia. Não é possível empilhar o livro.\n");
        return;
    }
    pilha->topo++; // Incrementa o topo
    strcpy(pilha->livros[pilha->topo], livro); // Copia o livro para o topo da pilha
}


//Executando pilha de livros
int main() {
    PilhaLivros pilha;
    inicializarPilha(&pilha);

    // Empilhando os livros fornecidos
    empilharLivro(&pilha, "Livro A");
    empilharLivro(&pilha, "Livro B");
    empilharLivro(&pilha, "Livro C");
    empilharLivro(&pilha, "Livro D");
    empilharLivro(&pilha, "Livro E");

    // Exibindo os livros empilhados (opcional)
    printf("Livros empilhados:\n");
    for (int i = 0; i <= pilha.topo; i++) {
        printf("%s\n", pilha.livros[i]);
    }

    return 0;
}
