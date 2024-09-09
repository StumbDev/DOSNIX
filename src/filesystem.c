#include "filesystem.h"
#include <dos.h>
#include <string.h>

void dos_read_file(const char *filename, char *buffer, unsigned int length) {
    union REGS regs;
    struct SREGS sregs;

    regs.h.ah = 0x3D;
    regs.h.al = 0;
    regs.x.dx = FP_OFF(filename);
    sregs.ds = FP_SEG(filename);
    intdosx(&regs, &regs, &sregs);

    int file_handle = regs.x.ax;

    regs.h.ah = 0x3F;
    regs.x.bx = file_handle;
    regs.x.cx = length;
    regs.x.dx = FP_OFF(buffer);
    sregs.ds = FP_SEG(buffer);
    intdosx(&regs, &regs, &sregs);

    regs.h.ah = 0x3E;
    regs.x.bx = file_handle;
    intdos(&regs, &regs);
}

void convert_unix_path_to_dos(const char *unix_path, char *dos_path) {
    strcpy(dos_path, "C:\\DOSNIX");
    strcat(dos_path, unix_path + 1);
    for (int i = 0; dos_path[i] != '\0'; i++) {
        if (dos_path[i] == '/') {
            dos_path[i] = '\\';
        }
    }
}
