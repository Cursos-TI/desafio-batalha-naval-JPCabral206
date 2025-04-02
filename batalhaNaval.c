#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10 // Define o tamanho do tabuleiro 10x10
#define NAVIO 'N' // Define o caractere que representa um navio
#define AGUA '~' // Define o caractere que representa a água

// Definição das linhas e colunas do tabuleiro
char linha[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int coluna[TAMANHO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char tabuleiro[TAMANHO][TAMANHO]; // Matriz que representa o tabuleiro
int opcao; // Variável para armazenar a opção do menu

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA; // Preenche todas as posições com '~'
        }
    }
}

// Função para exibir o tabuleiro
void mostrarTabuleiro() {
    printf("   ====================================\n"); // Linha superior
    printf("     ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%c  ", linha[i]); // Exibe os identificadores das colunas
    }
    printf("\n   ====================================\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d | ", coluna[i]); // Exibe os números das linhas
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c  ", tabuleiro[i][j]); // Exibe o conteúdo de cada célula
        }
        printf("|\n");
    }
    printf("   ====================================\n"); // Linha inferior
}

// Função para adicionar um navio ao tabuleiro
void adicionarNavio() {
    int l, c, escolha;
    printf("\n Escolha a direcao do navio\n");
    printf(" 1 - Vertical\n 2 - Horizontal\n 3 - Diagonal\n");
    printf(" Opcao: ");
    scanf("%d", &escolha);

    printf(" Digite a linha 0 a 9: ");
    scanf("%d", &l);
    printf(" Digite a coluna 0 a 9: ");
    scanf("%d", &c);

    if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) { // Verifica se a posição é válida
        if (escolha == 1 && l + 2 < TAMANHO) { // Adiciona navio vertical
            tabuleiro[l][c] = NAVIO;
            tabuleiro[l + 1][c] = NAVIO;
            tabuleiro[l + 2][c] = NAVIO;
            printf(" Navio adicionado verticalmente\n");
        } else if (escolha == 2 && c + 2 < TAMANHO) { // Adiciona navio horizontal
            tabuleiro[l][c] = NAVIO;
            tabuleiro[l][c + 1] = NAVIO;
            tabuleiro[l][c + 2] = NAVIO;
            printf(" Navio adicionado horizontalmente\n");
        } else if (escolha == 3 && l + 2 < TAMANHO && c + 2 < TAMANHO) { // Adiciona navio diagonal
            tabuleiro[l][c] = NAVIO;
            tabuleiro[l + 1][c + 1] = NAVIO;
            tabuleiro[l + 2][c + 2] = NAVIO;
            printf(" Navio adicionado diagonalmente\n");
        } else {
            printf(" Espaco insuficiente para o navio\n");
        }
    } else {
        printf(" Coordenadas invalidas\n");
    }
}

// Função principal do jogo
int main() {
    inicializarTabuleiro(); // Preenche o tabuleiro com água
    
    // Exibe o título do jogo
    printf("====================================\n");
    printf("          BATALHA NAVAL            \n");
    printf("====================================\n");
    
    do {
        // Exibe o menu de opções
        printf("\n 1 - Mostrar Tabuleiro\n 2 - Adicionar Navio\n 3 - Sair\n");
        printf(" Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarTabuleiro(); // Mostra o tabuleiro
                break;
            case 2:
                adicionarNavio(); // Adiciona um navio ao tabuleiro
                break;
            case 3:
                printf(" Saindo...\n"); // Encerra o programa
                break;
            default:
                printf(" Opcao invalida\n"); // Mensagem de erro
                break;
        }
    } while (opcao != 3); // O loop continua até que o usuário escolha sair
    
    return 0; // Encerra o programa
}