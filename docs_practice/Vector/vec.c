#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Vector {
    int* vec;
    int size;
    int capacity;
} typedef Vector;

void erase(Vector* vector, int index) {
    if (index  < 0 || index > vector -> capacity) return;

    for(int i = index; i < vector -> size; i++) {
        int tmp = vector -> vec [i];
        vector -> vec[i] = vector-> vec[i + 1]; // [5, 7, 1, 5, 2] 0 // [5, 1, 5, 2] index 2
        vector -> vec[i + 1] = tmp;
    }
    vector -> vec[vector -> size - 1] = - 1;
    vector -> vec = (int*) realloc (vector -> vec, (vector -> size - 1) * sizeof (int));
    vector -> size--;
}

void insert(Vector* vector, int index, int value) {
    if (index < 0 || index > vector -> capacity) return;

    if (vector -> size == vector -> capacity) {
        vector -> vec = (int*) realloc(vector -> vec, (vector -> capacity + 1) * sizeof(int));
        vector -> capacity++;
    }
    for (int i = vector -> size; i < index; i--) {
        vector -> vec[i] = vector -> vec[i -1];
    }
    vector -> vec[index] = value;
    vector -> size++;
}

void pop_back(Vector* vector) {
    vector -> size--;
}

int at(const Vector* vector, int index) {
    return vector -> vec[index];
}

bool empty(const Vector* vector) {
    return !(vector->size > 0);
}

int size (const Vector* vector) {
    return vector -> size;
}

int capacity (const Vector* vector) {
    return vector -> capacity;
}

void initilizeVector(Vector* vector, int count) {
    vector -> capacity = count;
    vector -> size = 0;
    vector -> vec = (int*) malloc(vector -> capacity * sizeof(int));
}

void push_back(Vector* vector, int element) {
    if (vector -> size == vector->capacity) {
        vector -> capacity *= 2;
        vector -> vec = (int*) realloc(vector -> vec, vector -> capacity * sizeof(int));
    } 

    vector -> vec[vector -> size] = element;
    vector -> size++;

}

int main () {
    Vector vector = {
        .capacity = 0,
        .vec = (int*) malloc(sizeof(int)),
        .size = 0
    };

    initilizeVector(&vector, 1);
    push_back(&vector, 10);
    push_back(&vector, 20);
    push_back(&vector, 30);

    insert(&vector, 1, 5000);
    erase(&vector, 2);

    for (int i = 0; i < vector.size; i++) {
        printf("%d     ", vector.vec[i]);
    }
}