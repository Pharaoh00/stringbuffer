#ifndef _STRING_BUFFER_H_
#define _STRING_BUFFER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

#endif // _STRING_BUFFER_H_