#include "./stringbuffer.h"

StringBuffer *initializeString(size_t capacity) {
    StringBuffer *tmp  = (StringBuffer*)malloc(sizeof(StringBuffer));
    tmp->string = (char*)malloc(capacity+1);
    memset(tmp->string, '\0', capacity+1);
    tmp->length = 0;
    tmp->capacity = capacity+1;
};

StringBuffer *initializeStringWithCharacters(char *str) {

    if(str == NULL) return NULL;  

    size_t str_length = strlen(str);

    StringBuffer *tmp  = (StringBuffer*)malloc(sizeof(StringBuffer));
    tmp->string = (char*)malloc(str_length + 1);

    memcpy(tmp->string, str, str_length);
    tmp->string[str_length] = '\0';

    tmp->length = str_length;
    tmp->capacity = str_length + 1;
};

int overrideString(char *str, StringBuffer *string) {

    if(string == NULL || string->string == NULL || str == NULL) return -1;

    size_t str_length = strlen(str);
    size_t new_capacity = str_length + 1;

    if(new_capacity > string->capacity) {
        char *new_string = (char*)malloc(new_capacity);
        if(!new_string) return -1;

        memcpy(new_string, str, str_length);

        free(string->string);

        string->string = new_string;
        string->string[str_length] = '\0';

        string->capacity = new_capacity;
        string->length = str_length;

        return 1;

    };

    memcpy(string->string, str, str_length);
    
    string->string[str_length] = '\0';
    string->length = str_length;

    return 1;

};

int concatenateStrings(char* str, StringBuffer *string) {

    if(!string->string) return -1;

    size_t str_length = strlen(str);
    size_t new_capacity =  str_length + string->length + 1;

    if(new_capacity > string->capacity) {

        char *new_string = (char*)malloc(new_capacity);
        if(!new_string) return -1;

        memcpy(new_string, string->string, string->length);
        memcpy(new_string + string->length, str, new_capacity - string->length - 1);

        free(string->string);

        string->string = new_string;
        string->string[str_length] = '\0';

        string->capacity = new_capacity;
        string->length = str_length;

        return 1;
    };

    memcpy(string->string + string->length, str, str_length);
    
    string->string[str_length] = '\0';
    string->length = str_length;

    return 1;
};

/*
    If the length of str1 is less then str2, str2 is greater than str1.
    If the length of str1 is greater then str2, str2 is less then str1.
*/
int compareStrings(StringBuffer *str1, StringBuffer *str2) {

    if(str1 == NULL || str2 == NULL) return -2;

    if(str1->length < str2->length) return -1;
    if(str1->length > str2->length) return 1;

    for(int i = 0; i < str1->length; i++) {
        if(str1->string[i] < str2->string[i]) return -1;
        if(str1->string[i] > str2->string[i]) return 1;
    };

    return 0;
};