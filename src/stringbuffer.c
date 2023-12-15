#include "./stringbuffer.h"

StringBuffer *initializeString(size_t capacity) {
    StringBuffer *tmp  = (StringBuffer*)malloc(sizeof(StringBuffer));
    if(tmp == NULL) return NULL;

    tmp->string = (char*)malloc(capacity+1);
    if(tmp->string == NULL) return NULL;

    memset(tmp->string, '\0', capacity+1);
    tmp->length = 0;
    tmp->capacity = capacity+1;

    return tmp;
};

StringBuffer *initializeStringWithCharacters(char *str) {

    if(str == NULL) return NULL;  

    size_t str_length = strlen(str);

    StringBuffer *tmp  = (StringBuffer*)malloc(sizeof(StringBuffer));
    if(tmp == NULL) return NULL;

    tmp->string = (char*)malloc(str_length + 1);
    if(tmp->string == NULL) return NULL;

    memcpy(tmp->string, str, str_length);
    tmp->string[str_length] = '\0';

    tmp->length = str_length;
    tmp->capacity = str_length + 1;

    return tmp;
};

int freeString(StringBuffer *input) {

    if(input == NULL || input->string == NULL) return -1;

    free(input->string);
    free(input);
    input = NULL;

    return 1;
};

int overrideString(char *str, StringBuffer *string) {

    if(string == NULL || string->string == NULL || str == NULL) return -1;

    size_t str_length = strlen(str);
    size_t new_capacity = str_length + 1;

    if(new_capacity > string->capacity) {
        char *new_string = (char*)malloc(new_capacity);
        if(new_string == NULL) return -1;

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

    if(string == NULL || string->capacity == 0 || string->string == NULL || string->length == 0 || str == NULL || str[0] == '\0') return -1;

    size_t str_length = strlen(str);
    size_t new_capacity =  str_length + string->length + 1;

    if(new_capacity > string->capacity) {

        char *new_string = (char*)malloc(new_capacity);
        if(new_string == NULL) return -1;

        memcpy(new_string, string->string, string->length);
        memcpy(new_string + string->length, str, new_capacity - string->length - 1);

        free(string->string);

        string->capacity = new_capacity;
        string->length = str_length;

        string->string = new_string;
        string->string[str_length] = '\0';

        return 1;
    };

    memcpy(string->string + string->length, str, str_length);
    
    string->length = str_length;
    string->string[str_length] = '\0';

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

// TODO: Handle utf-8 characters.
int upperCaseString(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->string == NULL) return -1;

    for(int i = 0; i < string->length; i++) {
        if(characterIsLetter(string->string[i]) == 0) string->string[i] -= ASCII_SPACE_BETWEEN_LETTERS;
    };

    return 1;
};

// TODO: Handle utf-8 characters.
int lowerCaseString(StringBuffer *string) {
    if(string == NULL || string->capacity == 0 || string->string == NULL) return -1;

    for(int i = 0; i < string->length; i++) {
        if(characterIsLetter(string->string[i]) == 1) string->string[i] += ASCII_SPACE_BETWEEN_LETTERS;
    };

    return 1;
};

// TODO: Handle utf-8 characters.
int characterIsLetter(char ch) {

    if(ch >= 65 && ch <= 90) return UPPER_CASE_LETTER;
    if(ch >= 97 && ch <= 122) return LOWER_CASE_LETTER;

    return NOT_A_LETTER;
};

int characterIsNumber(char ch) {

    if(ch >= 48 && ch <= 57) return 1;

    return 0;
};

int characterIsSpace(char ch) {

    if(ch == 32) return 1;

    return 0;
};

// TODO: Handle utf-8 characters.
int stringIsAlpha(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->string == NULL) return -1;

    for(int i = 0; i < string->length; i++) {
        if(characterIsLetter(string->string[i]) == -1) return 0;
    };

    return 1;

};

// TODO: Handle utf-8 characters.
int stringIsAscii(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->string == NULL) return -1;   

    for(int i = 0; i < string->length; i++) {
        if(string->string[i] > 127) return 0;
    };

    return 1;
};

int stringIsNumber(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->string == NULL) return -1;

    for(int i = 0; i < string->length; i++) {
        if(characterIsNumber(string->string[i]) == 0) return 0;
    };

    return 1;
};

int stringIsLowerCase(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->string == NULL) return -1;

    for(int i = 0; i < string->length; i++) {
        if(characterIsLetter(string->string[i]) != LOWER_CASE_LETTER) return 0;
    };

    return 1;
};

int stringIsupperCase(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->string == NULL) return -1;

    for(int i = 0; i < string->length; i++) {
        if(characterIsLetter(string->string[i]) != UPPER_CASE_LETTER) return 0;
    };

    return 1;
};

ssize_t findCharacter(char *ch, StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->string == NULL || string->length == 0 || ch == NULL || ch[0] == '\0') return -1;

    char *pointer = memchr(string->string, ch[0], string->length);
    if(pointer == NULL) return -1;

    return pointer - string->string;
};

int stripString(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->length == 0 || string->string == NULL) return -1;

    char *tmp = (char*)malloc(string->capacity);
    if(tmp == NULL) return -1;

    int striped_index = 0;

    for(int i = 0; i < string->length; i++) {
        if(!isspace(string->string[i])) {
            tmp[striped_index] = string->string[i];
            striped_index++;
        };
    };

    tmp[striped_index] = '\0';

    free(string->string);

    string->string = tmp;
    string->length = striped_index;

    return 1;

};

int resizeCapacity(StringBuffer *string) {

    if(string == NULL || string->capacity == 0 || string->length == 0 || string->string == NULL) return -1;

    char *tmp = (char*)malloc(string->length+1);
    if(tmp == NULL) return -1;

    memcpy(tmp, string->string, string->length);
    tmp[string->length] = '\0';

    free(string->string);

    string->string = tmp;

    return 1;
};

StringBuffer** splitString(StringBuffer* input, char delimiter) {
    if (input == NULL || input->string == NULL || input->length == 0) return NULL;

    size_t how_many_splits = 1;
    for (size_t i = 0; i < input->length; i++) {
        if (input->string[i] == delimiter) how_many_splits++;
    };

    StringBuffer** tokens = (StringBuffer**)malloc((how_many_splits + 1) * sizeof(StringBuffer));
    if (tokens == NULL) return NULL;

    size_t token_index = 0;
    size_t token_start = 0;

    for (size_t i = 0; i <= input->length; i++) {
        if (input->string[i] == delimiter || i == input->length) {
            
            size_t tokenLength = i - token_start;
            tokens[token_index] = initializeString(tokenLength);
            if (tokens[token_index] == NULL) {
                
                for (size_t j = 0; j < token_index; j++) {
                    freeString(tokens[j]);
                };
                free(tokens);
                return NULL;
            };

            memcpy(tokens[token_index]->string, input->string + token_start, tokenLength);
            tokens[token_index]->length = tokenLength;

            token_start = i + 1;
            token_index++;
        };
    };

    tokens[how_many_splits] = NULL;
    return tokens;
};
