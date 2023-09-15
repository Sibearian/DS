#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ArrayList {
    int* arr;
    int len;
    int cap;
};

typedef struct ArrayList List;

List* getNewList();
void freeList(List *l);
void push(List *l, int i);
int pop(List *l);
void printList(List *l);

int main(){
    printf("Creating new list...\n");
    List *list = getNewList();
    for(int i = 0; i < 22; i++){
        push(list, i);
        if(i % 5 == 0){
            printList(list);
        }
    }
    printList(list);
    for(int i = 0; i < 25; i++){
        printf("poped : %d\n", pop(list));
        if(i % 5 == 0){
            printList(list);
        }
    }
    printList(list);
    freeList(list);
    printf("freeing the list...\n");
    return 0;
}

// ======= Implimentation =========

List* getNewList(){
    List *new = (List*)malloc(sizeof(List));
    new->arr = (int*)malloc(sizeof(int) * 10);
    new->len = 0;
    new->cap = 10;
    return new;
}

void freeList(List *l){
    printf("list of len : %d and capacity : %d has been freed\n", l->len, l->cap);
    free(l->arr);
    free(l);
    return;
}

void printList(List *l){
    int* arr = l->arr;
    printf("[");
    for(int i = 0; i < l->len - 1; i++){
        printf("%d, ", arr[i]);
    }
    if (l->len != 0){
        printf("%d]\n", arr[l->len - 1]);
    } else {
        printf("]\n");
    }
    return;
}

void push(List *l, int item){
    if(l->len == l->cap){
        int* newArr = (int*)malloc(sizeof(int) * (l->cap * 2));
        for(int i = 0; i < l->len; i++){
            newArr[i] = l->arr[i];
        }
        free(l->arr);
        l->arr = newArr;
        l->cap *= 2;
    }
    
    l->arr[l->len] = item;
    l->len++;
    return;
} 

int pop(List *l){
    if(l->len == 0){
        printf("Empty List");
        return -1;
    }

    int poped = l->arr[l->len - 1];
    l->arr[l->len - 1] = 0;
    l->len--;
    return poped;
}

