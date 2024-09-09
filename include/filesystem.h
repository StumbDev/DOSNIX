#ifndef FILESYSTEM_H
#define FILESYSTEM_H

void dos_read_file(const char *filename, char *buffer, unsigned int length);
void convert_unix_path_to_dos(const char *unix_path, char *dos_path);

#endif // FILESYSTEM_H
