#include <unistd.h>

int read_word(int fd) {
    int word;
    read(fd, &word, sizeof(int));
    return word;
}

short read_half(int fd) {
    short half;
    read(fd, &half, sizeof(short));
    return half;
}

void write_word(int fd, int word) {
    write(fd, &word, sizeof(int));
}

void write_half(int fd, short half) {
    write(fd, &half, sizeof(short));
}