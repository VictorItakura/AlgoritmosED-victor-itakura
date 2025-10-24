#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int ascii;
    int freq;
} Item;

int cmp(const void *a, const void *b) {
    Item *x = (Item *)a;
    Item *y = (Item *)b;

    // Ordem crescente por frequência
    if (x->freq != y->freq)
        return x->freq - y->freq;
    // Se iguais, ordem decrescente por valor ASCII
    return y->ascii - x->ascii;
}

int main() {
    char line[1005];
    int first = 1;

    while (fgets(line, sizeof(line), stdin)) {
        int freq[128] = {0}; // tabela ASCII até 127

        for (int i = 0; line[i] != '\0'; i++) {
            unsigned char c = line[i];
            if (c >= 32 && c <= 127)
                freq[c]++;
        }

        Item arr[128];
        int count = 0;
        for (int i = 32; i < 128; i++) {
            if (freq[i] > 0) {
                arr[count].ascii = i;
                arr[count].freq = freq[i];
                count++;
            }
        }

        qsort(arr, count, sizeof(Item), cmp);

        if (!first) printf("\n"); // linha em branco entre casos
        first = 0;

        for (int i = 0; i < count; i++) {
            printf("%d %d\n", arr[i].ascii, arr[i].freq);
        }
    }

    return 0;
}
