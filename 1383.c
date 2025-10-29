#include <stdio.h>

#define N 9

int valida_linha(int grid[N][N], int r) {
    int seen[10] = {0}; // índices 1..9
    for (int c = 0; c < N; c++) {
        int v = grid[r][c];
        if (v < 1 || v > 9) return 0;
        if (seen[v]) return 0;
        seen[v] = 1;
    }
    // opcional checar se todos 1..9 apareceram, mas já garantimos sem repetir e tamanho 9
    return 1;
}

int valida_coluna(int grid[N][N], int c) {
    int seen[10] = {0};
    for (int r = 0; r < N; r++) {
        int v = grid[r][c];
        if (v < 1 || v > 9) return 0;
        if (seen[v]) return 0;
        seen[v] = 1;
    }
    return 1;
}

int valida_bloco(int grid[N][N], int startR, int startC) {
    int seen[10] = {0};
    for (int r = startR; r < startR + 3; r++) {
        for (int c = startC; c < startC + 3; c++) {
            int v = grid[r][c];
            if (v < 1 || v > 9) return 0;
            if (seen[v]) return 0;
            seen[v] = 1;
        }
    }
    return 1;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    for (int caso = 1; caso <= t; caso++) {
        int grid[N][N];

        // lê a matriz 9x9
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                scanf("%d", &grid[r][c]);
            }
        }

        int valido = 1;

        // valida todas as linhas
        for (int r = 0; r < N && valido; r++) {
            if (!valida_linha(grid, r)) {
                valido = 0;
            }
        }

        // valida todas as colunas
        for (int c = 0; c < N && valido; c++) {
            if (!valida_coluna(grid, c)) {
                valido = 0;
            }
        }

        // valida todos os blocos 3x3
        for (int r = 0; r < N && valido; r += 3) {
            for (int c = 0; c < N && valido; c += 3) {
                if (!valida_bloco(grid, r, c)) {
                    valido = 0;
                }
            }
        }

        // saída no formato pedido
        printf("Instancia %d\n", caso);
        if (valido)
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }

    return 0;
}
