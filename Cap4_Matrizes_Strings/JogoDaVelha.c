// Exemplo simples de jogo da velha 

#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]; // Matriz tabuleiro do Jogo

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

void main(void) {
    
    char done;

    printf("\nEste é jogo da velha.\n");
    printf("Você estará jogando contra o computador.\n\n");

    done = ' ';
    init_matrix();
    do {
        disp_matrix();
        get_player_move();
        done = check(); // Verifica se há vencedor após primeira jogada
        if(done != ' ') break; // Houve vencedor
        get_computer_move();
        done = check(); // Verifica se há vencedor após segunda jogada
    } while (done == ' ');

    if (done == 'X') printf("Você ganhou!\n\n");
    else printf("Eu ganhei!!!\n\n");

    disp_matrix(); // Mostra as posições finais
}

// Inicializa a matriz tabuleiro
void init_matrix(void) {

    int i, j;
    for(i = 0; i < 3; i++) 
        for(j = 0; j < 3; j++) matrix[i][j] = ' ';
}

// Obtém sua jogada
void get_player_move(void) {

    int x, y;

    printf("\nDigite as coordenadas da sua jogada: ");
    scanf("%d%d", &x,&y);
    x--; y--;
    printf("\n");
    if(matrix[x][y] != ' ') {
        printf("\nPosição inválida, tente novamente. \n");
        get_player_move;
    } 
    else matrix[x][y] = 'X';
}

// Obtém uma jogada do computador
void get_computer_move(void) {

    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            if (matrix[i][j] == ' ') break;
        if(matrix[i][j] == ' ') break;
    }

    if(i * j == 9) {
        printf("Empate!\n");
        exit(0);
    }
    else matrix[i][j] = 'O';
}

// Mostra a matriz na tela
void disp_matrix(void) {

    int t;

    for(t = 0; t < 3 ; t++) {
        printf(" %c | %c | %c ",matrix[t][0], matrix[t][1], matrix[t][2]);
        if(t != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Verifica se há um vencedor
char check(void) {

    int i;

    for(i = 0; i < 3; i++) // Verifica as linhas
        if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) return matrix[i][0];
    
    for(i = 0; i < 3; i++) // Verifica as colunas
        if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) return matrix[0][i];
    
    // Testa as diagonais
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) return matrix[0][0];
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) return matrix[0][2];

    return ' ';
}

