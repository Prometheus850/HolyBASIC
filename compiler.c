#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VARS 26
int vars[MAX_VARS]; // переменные A-Z

void run_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Не удалось открыть файл: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "PRINT ", 6) == 0) {
            printf("%s", line + 6);
        } else if (strncmp(line, "LET ", 4) == 0) {
            char var = line[4]; // переменная A-Z
            int val = atoi(line + 7); // LET X = 5
            vars[var - 'A'] = val;
        } else if (strncmp(line, "END", 3) == 0) {
            break;
        }
    }

    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        run_file(argv[1]); // запуск HolyBASIC файла
    } else {
        char line[256];
        printf("HolyBASIC Interpreter\n");
        while (1) {
            printf("> ");
            if (!fgets(line, sizeof(line), stdin)) break;

            if (strncmp(line, "PRINT ", 6) == 0) {
                printf("%s", line + 6);
            } else if (strncmp(line, "LET ", 4) == 0) {
                char var = line[4];
                int val = atoi(line + 7);
                vars[var - 'A'] = val;
            } else if (strncmp(line, "END", 3) == 0) {
                break;
            }
        }
    }

    return 0;
}
