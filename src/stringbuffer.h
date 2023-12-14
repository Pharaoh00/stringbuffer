#ifndef _STRING_BUFFER_H_
#define _STRING_BUFFER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_SPACE_BETWEEN_LETTERS 32
#define UPPER_CASE_LETTER 1
#define LOWER_CASE_LETTER 0
#define NOT_A_LETTER -1

typedef struct String {
    char *string;
    size_t length;
    size_t capacity;

} StringBuffer;

StringBuffer *initializeString(size_t capacity);
StringBuffer *initializeStringWithCharacters(char *str);
int concatenateStrings(char* str, StringBuffer *string);
int compareStrings(StringBuffer *str1, StringBuffer *str2);
int overrideString(char *str, StringBuffer *string);
int capitalizeString(StringBuffer *string);
int casefoldString(StringBuffer *string);
int characterIsLetter(char ch);
int characterIsNumber(char ch);

#endif // _STRING_BUFFER_H_