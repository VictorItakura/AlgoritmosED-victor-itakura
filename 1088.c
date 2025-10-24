#include <stdio.h>

#define MAXN 100000

static long long bit[MAXN + 1];
static int a[MAXN + 5];
int N;

static void bit_clear(int n){
    for (int i = 1; i <= n; i++) bit[i] = 0;
}

static void bit_add(int idx, int n, int val){
    while (idx <= n){
        bit[idx] += val;
        idx += idx & -idx;
    }
}

static long long bit_sum(int idx){
    long long s = 0;
    while (idx > 0){
        s += bit[idx];
        idx -= idx & -idx;
    }
    return s;
}

int main(void){
    while (scanf("%d", &N) == 1 && N){
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);

        bit_clear(N);
        long long inversoes = 0;

        // Conta quantos maiores já vistos existem para cada a[i]
        for (int i = 0; i < N; i++){
            // elementos já inseridos = i
            // menores/iguais até a[i] = bit_sum(a[i])
            long long menoresOuIguais = bit_sum(a[i]);
            inversoes += i - menoresOuIguais;
            bit_add(a[i], N, 1);
        }

        if (inversoes % 2) puts("Marcelo");
        else               puts("Carlos");
    }
    return 0;
}
