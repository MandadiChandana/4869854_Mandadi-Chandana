#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int superDigitHelper(long long n) {
    if (n < 10) return n;
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return superDigitHelper(sum);
}

int superDigit(char* n, int k) {
    long long sum = 0;
    for (int i = 0; n[i]; i++) {
        sum += n[i] - '0';
    }
    sum *= k;
    return superDigitHelper(sum);
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (1) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
    }
    if (data[data_length - 1] == '\n') data[data_length - 1] = '\0';
    return data;
}

char* ltrim(char* str) {
    while (*str && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int count = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * (count + 1));
        splits[count++] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    return strtol(str, NULL, 10);
}

int main() {
    char** first_multiple_input = split_string(rtrim(readline()));
    char* n = first_multiple_input[0];
    int k = parse_int(first_multiple_input[1]);
    int result = superDigit(n, k);
    printf("%d\n", result);
    return 0;
}
