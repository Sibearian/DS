#include <stdio.h>
#include <stdlib.h>

struct STRING {
    char *ptr;
    unsigned int len;
};

typedef struct STRING string;

string* getStr(int len);
void freeString(string* str);
string* toString(const char* s);
string* concat(string* str1, string* str2);
string* join(string* join, string** strings, unsigned int size);
void print(string* str);

int main(){
    string *array[3] = {toString("Hello"), toString("world"), toString("!")};
    string *joinS = toString(" ");
    string *joined= join(joinS, array, 3);

    print(joined);

    freeString(joined);
    freeString(joinS);
    freeString(array[0]);
    freeString(array[1]);
    freeString(array[2]);
}

// ---------------------------------

string* getStr(int len){
    if(len < 0){
        return NULL;
    }

    string* str = (string *) malloc(sizeof(string));
    if(str == NULL) {
        return NULL;
    }

    str->ptr = (char *) calloc(len, sizeof(char));
    if(str->ptr == NULL) {
        free(str);
        return NULL;
    }

    str->len = len;
    return str;
}

string* toString(const char* s){
    unsigned int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    
    if(count < 0){
        return NULL;
    }

    string* res = getStr(count);
    if(res == NULL){
        return res;
    }

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

string* concat(string* str1, string* str2){
    string* str = getStr(str1->len + str2->len);
    if(str == NULL){
        return NULL;
    }

    for(int i = 0; i < str1->len; i++){
        str->ptr[i] = str1->ptr[i];
    }

    for(int i = 0; i < str2->len; i++){
        str->ptr[i + str1->len] = str2->ptr[i];
    }

    return str;
}

string* join(string* join, string** strings, unsigned int size){
    string *str = getStr(0), *temp, *tt;
    for(int i = 0; i < size -1; i++){
        temp = concat(strings[i], join);
        if (temp == NULL){
            freeString(str);
            return NULL;
        }
        tt = str;
        str = concat(tt, temp);

        freeString(tt);
        freeString(temp);

        if(str == NULL) {
            return NULL;
        }
    }

    tt = str;
    str = concat(tt, strings[size - 1]);
    freeString(tt);

    if(str == NULL){
        return NULL;
    }
    
    return str;
}
