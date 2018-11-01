#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    int from = open("file1.txt", O_RDONLY);
    int to = open("file1.memcpy.txt", O_RDWR);
    size_t fp = lseek(from, 0, SEEK_END);

    char *from_text = mmap(NULL, fp, PROT_READ, MAP_PRIVATE, from, 0);
    char *to_text = mmap(NULL, fp, PROT_READ | PROT_WRITE, MAP_SHARED, to, 0);

    ftruncate(to, fp);

    memcpy(to_text, from_text, fp);

    munmap(from_text, fp);
    munmap(to_text, fp);

    close(from);
    close(to);
}