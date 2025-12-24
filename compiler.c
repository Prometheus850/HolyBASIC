#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VARS 26
int vars[MAX_VARS]; // переменные A-Z

int main() {
    char line[256];
    printf("HolyBASIC Interpreter\n");

    while (1) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) break;

        if (strncmp(line, "BLESS ", 6) == 0) {
            printf("%s", line + 6);
        } else if (strncmp(line, "LET ", 4) == 0) {
            char var = line[4];
            int val = atoi(line + 7);
            vars[var - 'A'] = val;
        } else if (strncmp(line, "FOR ", 4) == 0) {
            char var = line[4];
            int from = atoi(line + 7);
            char *to_ptr = strstr(line, "TO");
            int to = atoi(to_ptr + 3);
            for (int i = from; i <= to && i-from < 1000; i++) { // ограничение итераций
                vars[var - 'A'] = i;
                printf("Loop iteration: %d\n", i);
            }
        } else if (strncmp(line, "END", 3) == 0) {
            break;
        }
    }

    return 0;
}
