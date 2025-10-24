#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INIT_CAP 4096
#define MAXW 205  // palavra cabe em uma linha (<=200), com folga + '\0'

static int cmp_str(const void *a, const void *b) {
    const char *sa = *(const char **)a;
    const char *sb = *(const char **)b;
    return strcmp(sa, sb);
}

int main(void) {
    char **vec = NULL;
    size_t cap = 0, len = 0;

    // Inicializa vetor dinâmico
    cap = INIT_CAP;
    vec = (char **)malloc(cap * sizeof(char*));

    char w[MAXW];
    int wi = 0;

    int c;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (wi < MAXW - 1) {               // evita overflow
                w[wi++] = (char)tolower(c);
            }
        } else {
            if (wi > 0) {                       // finaliza palavra
                w[wi] = '\0';
                if (len == cap) {               // cresce vetor
                    cap *= 2;
                    vec = (char **)realloc(vec, cap * sizeof(char*));
                }
                vec[len] = (char *)malloc((wi + 1) * sizeof(char));
                strcpy(vec[len], w);
                len++;
                wi = 0;
            }
        }
    }
    // flush final se terminou com letra
    if (wi > 0) {
        w[wi] = '\0';
        if (len == cap) {
            cap *= 2;
            vec = (char **)realloc(vec, cap * sizeof(char*));
        }
        vec[len] = (char *)malloc((wi + 1) * sizeof(char));
        strcpy(vec[len], w);
        len++;
    }

    // Ordena e imprime sem repetição
    qsort(vec, len, sizeof(char*), cmp_str);

    if (len > 0) {
        puts(vec[0]);
        for (size_t i = 1; i < len; i++) {
            if (strcmp(vec[i], vec[i - 1]) != 0)
                puts(vec[i]);
        }
    }

    // Libera memória
    for (size_t i = 0; i < len; i++) free(vec[i]);
    free(vec);

    return 0;
}
