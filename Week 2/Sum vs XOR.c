#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long sumXor(long n) {
    if (n == 0) return 1;
    long count = 0;
    long temp = n;
    while (temp > 0) {
        if ((temp & 1) == 0) count++;
        temp >>= 1;
    }
    long result = 1;
    while (count--) result *= 2;
    return result;
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
long parse_long(char* str) { return strtol(str, NULL, 10); }

int main() {
    long n = parse_long(ltrim(rtrim(readline())));
    long result = sumXor(n);
    printf("%ld\n", result);
    return 0;
}
