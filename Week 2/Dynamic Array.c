#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} DynArray;

void append(DynArray* arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity = arr->capacity == 0 ? 1 : arr->capacity * 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

int dynamicArrayValue(DynArray* arr, int index) {
    return arr->data[index];
}

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    DynArray* seqList = malloc(n * sizeof(DynArray));
    for (int i = 0; i < n; i++) {
        seqList[i].data = NULL;
        seqList[i].size = 0;
        seqList[i].capacity = 0;
    }

    int* results = malloc(queries_rows * sizeof(int));
    *result_count = 0;
    int lastAnswer = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            append(&seqList[idx], y);
        } else if (type == 2) {
            lastAnswer = dynamicArrayValue(&seqList[idx], y % seqList[idx].size);
            results[(*result_count)++] = lastAnswer;
        }
    }

    for (int i = 0; i < n; i++) free(seqList[i].data);
    free(seqList);

    return results;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int** queries = malloc(q * sizeof(int*));
    for (int i = 0; i < q; i++) {
        queries[i] = malloc(3 * sizeof(int));
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    int result_count;
    int* result = dynamicArray(n, q, 3, queries, &result_count);

    for (int i = 0; i < result_count; i++) printf("%d\n", result[i]);
    free(result);

    for (int i = 0; i < q; i++) free(queries[i]);
    free(queries);

    return 0;
}
