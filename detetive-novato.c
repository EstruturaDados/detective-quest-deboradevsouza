#include <stdio.h>
#include <stdlib.h>

// Estrutura da sala
struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
};

// Função para criar uma nova sala
struct Sala* criarSala(char* nome) {
    struct Sala* nova = (struct Sala*) malloc(sizeof(struct Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Função para conectar salas (lado esquerdo e direito)
void conectarSalas(struct Sala* raiz, struct Sala* esquerda, struct Sala* direita) {
    if (raiz != NULL) {
        raiz->esquerda = esquerda;
        raiz->direita = direita;
    }
}

// Função para explorar a mansão
void explorarSalas(struct Sala* atual) {
    char opcao;

    while (1) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        printf("Para onde deseja ir?\n");
        if (atual->esquerda != NULL) printf("  (e) Ir para a esquerda -> %s\n", atual->esquerda->nome);
        if (atual->direita != NULL) printf("  (d) Ir para a direita -> %s\n", atual->direita->nome);
        printf("  (s) Sair da exploração\n");
        printf("> ");
        scanf(" %c", &opcao);

        if (opcao == 's') {
            printf("\nVocê decidiu sair da mansão.\n");
            break;
        } else if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else {
            printf("\nCaminho inválido!\n");
        }
    }
}

int main() {
    // Criando as salas
    struct Sala* hall = criarSala("Hall de Entrada");
    struct Sala* biblioteca = criarSala("Biblioteca");
    struct Sala* cozinha = criarSala("Cozinha");
    struct Sala* sotao = criarSala("Sótão");
    struct Sala* jardim = criarSala("Jardim");

    // Conectando as salas (árvore fixa)
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, sotao, NULL);
    conectarSalas(cozinha, NULL, jardim);

    // Começar exploração
    printf("=== Mapa da Mansão ===\n");
    explorarSalas(hall);

    // Liberar memória
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(jardim);

    return 0;
}