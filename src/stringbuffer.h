#ifndef _STRING_BUFFER_H_
#define _STRING_BUFFER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>

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
int freeString(StringBuffer *input);
int concatenateStrings(char* str, StringBuffer *string);
int compareStrings(StringBuffer *str1, StringBuffer *str2);
int overrideString(char *str, StringBuffer *string);
int upperCaseString(StringBuffer *string);
int lowerCaseString(StringBuffer *string);
int characterIsLetter(char ch);
int characterIsNumber(char ch);
int characterIsSpace(char ch);
int stringIsAlpha(StringBuffer *string);
int stringIsAscii(StringBuffer *string);
int stringIsNumber(StringBuffer *string);
int stringIsLowerCase(StringBuffer *string);
int stringIsupperCase(StringBuffer *string);
ssize_t findCharacter(char *ch, StringBuffer *string);
int stripString(StringBuffer *string);
int resizeCapacity(StringBuffer *string);
StringBuffer **splitString(StringBuffer *string, char delimiter);

#endif // _STRING_BUFFER_H_