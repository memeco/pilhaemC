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

// Função para desempilhar um livro
void desempilharLivro(PilhaLivros *pilha) {
    // Verifica se a pilha está vazia
    if (pilha->topo == -1) { 
        printf("Erro: Pilha vazia. Não é possível remover o livro.\n");
        return;
    }
    // Mostra o livro a ser removido
    printf("Livro removido: %s\n", pilha->livros[pilha->topo]);
    // Decrementa o topo
    pilha->topo--; 
}

//Executando pilha de livros
int main() {
    PilhaLivros pilha;
    inicializarPilha(&pilha);

    // Desempilhando um livro (pilha vazia)
    desempilharLivro(&pilha);

    // Empilhando os livros fornecidos
    empilharLivro(&pilha, "Livro A");
    empilharLivro(&pilha, "Livro B");
    empilharLivro(&pilha, "Livro C");
    empilharLivro(&pilha, "Livro D");
    empilharLivro(&pilha, "Livro E");

    // Exibindo os livros empilhados (opcional)
    printf("Livros empilhados:\n");
    for (int i = pilha.topo; i >= 0;  i--) {
        printf("%s\n", pilha.livros[i]);
    }

    // Desempilhando um livro
    desempilharLivro(&pilha);

    // Exibindo os livros empilhados após a remoção (opcional)
    printf("Livros empilhados após a remoção:\n");
    for (int i = pilha.topo; i >= 0;  i--) {
        printf("%s\n", pilha.livros[i]);
    }

    return 0;
}
