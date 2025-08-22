#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* counterGame(long n) {
    int turnCount = 0;
    while (n > 1) {
        if ((n & (n - 1)) == 0) {
            n /= 2;
        } else {
            long power = 1;
            while (power * 2 < n) power *= 2;
            n -= power;
        }
        turnCount++;
    }
    return (turnCount % 2 == 1) ? "Louise" : "Richard";
}

char* readline() {
    size_t length = 1024, offset = 0;
    char* buffer = malloc(length);
    while (1) {
        char* cursor = buffer + offset;
        char* line = fgets(cursor, length - offset, stdin);
        if (!line) break;
        offset += strlen(cursor);
        if (offset < length - 1 || buffer[offset - 1] == '\n') break;
        length *= 2;
        buffer = realloc(buffer, length);
    }
    if (buffer[offset - 1] == '\n') buffer[offset - 1] = '\0';
    return buffer;
}

char* ltrim(char* str) { while (*str && isspace(*str)) str++; return str; }
char* rtrim(char* str) { char* end = str + strlen(str) - 1; while (end >= str && isspace(*end)) end--; *(end + 1) = '\0'; return str; }
int parse_int(char* str) { return strtol(str, NULL, 10); }
long parse_long(char* str) { return strtol(str, NULL, 10); }

int main() {
    int t = parse_int(ltrim(rtrim(readline())));
    for (int i = 0; i < t; i++) {
        long n = parse_long(ltrim(rtrim(readline())));
        printf("%s\n", counterGame(n));
    }
    return 0;
}
