#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char line[1001];
    
    scanf("%d", &N);
    getchar(); // consome o '\n' após o número

    for (int i = 0; i < N; i++) {
        fgets(line, 1001, stdin); // lê a linha
        int open = 0, diamonds = 0;

        for (int j = 0; line[j] != '\0'; j++) {
            if (line[j] == '<') {
                open++;
            } else if (line[j] == '>' && open > 0) {
                open--;
                diamonds++;
            }
        }

        printf("%d\n", diamonds);
    }

    return 0;
}
