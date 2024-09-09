#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LEGTH 128
#define BUFFER_SIZE 1024

void execute_command(const char *command) {
    union REGS regs;
    regs.h.ah = 0x4B; // dos function to execute a prg
    regs.h.al = 0x00; // no wait flag
    regs.h.dx = (unsigned int)command;
    intdos(&regs, &regs);
}

void print_prompt() {
    printf("i: ");
}

void shell() {
    char command[MAX_COMMAND_LEGTH];

    while (1)
    {
        print_prompt();
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character
        if (strncmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "cat", 4) == 0) 
        {
           FILE *file = fopen(command + 4, "r");
           if (file)
           {
            char buffer[BUFFER_SIZE];
            while (fgets(buffer, sizeof(buffer), file))
            {
                printf("%s", buffer);
            }
            fclose(file);
           } else {
            printf("cat: Error: File not found.\n");
           }
        } else if (strcmp(command, "echo ", 5) == 0) {
            printf("%s\n", command + 5);
        } else {
            execute_command(command);
        }
    }
}

int main() {
    printf("MIGLIC UNIX\n");
    shell();
    printf("Shutting down...");
    power();
    return 0;
}