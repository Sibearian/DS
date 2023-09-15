#include <stdio.h>
#include <stdlib.h>

struct STRING {
    char *ptr;
    unsigned int len;
};

typedef struct STRING string;

string* newString(const char* s);
void print(string* str);
void freeString(string* str);

int main(){
    string *hello = newString("Hello World!");
    print(hello);
    freeString(hello);
}

// ---------------------------------

string* newString(const char* s){
    unsigned int count = 0;
    while (s[count] != '\0') {
        count++;
    }

    string *res = (string *)malloc(sizeof(string));
    res->len = count;
    res->ptr = (char *)malloc(sizeof(char) * count);

    for(int i = 0; i < count; i++){
        res->ptr[i] = s[i];
    }

    return res;
}

void print(string* str){
    for(int i = 0; i < str->len; i++){
        printf("%c", str->ptr[i]);
    }
    printf("\n");
}

void freeString(string* str){
    free(str->ptr);
    free(str);
}
