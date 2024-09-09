#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <dir.h>

void shell() {
    char command[256];

    while (1) {
        printf("i: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "ls") == 0) {
            ls_command();
        } else if (strncmp(command, "cp ", 3) == 0) {
            char *args = command + 3;
            char *src = strtok(args, " ");
            char *dest = strtok(NULL, " ");
            cp_command(src, dest);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Command not found: %s\n", command);
        }
    }
}

void ls_command() {
    struct ffblk ffblk;
    int done = findfirst("*.*", &ffblk, 0);

    while (!done) {
        printf("%s\n", ffblk.ff_name);
        done = findnext(&ffblk);
    }
}

void uname_command() {
    // make uname command
}

void cp_command(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    char buffer[512];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}
