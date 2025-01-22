//
// Created by pablo on 22/01/2025.
//

#include "lexer.h";

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tokenization(const char **raw) {
    char buffer[100];
    int i = 0;
    while (isalpha(**raw)) {
        buffer[i++] = **raw;
        (*raw)++;
    }
    buffer[i] = '\0';
    return strdup(buffer);
}

char *digitTokenization(const char **raw) {
    char buffer[100];
    int i = 0;
    while (isdigit(**raw)) {
        buffer[i++] = **raw;
        (*raw)++;
    }
    buffer[i] = '\0';
    return strdup(buffer);
}

Token *lexer(const char *source) {
    Token *tokens = malloc(sizeof(Token) * 100);
    int tokenCounter = 0;
    while (*source != '\0') {
        while (isspace(*source)) {
            source++;
        }

        if (isalpha(*source) && !isspace(*source)) {
            char *splittedToken = tokenization(&source);
            if (strcmp(splittedToken,VALUE_DEFINITION) == 0) {
                tokens[tokenCounter].type = TOKEN_DEFINITION;
                tokens[tokenCounter].value = splittedToken;
            } else {
                tokens[tokenCounter].type = TOKEN_IDENTIFIER;
                tokens[tokenCounter].value = splittedToken;
            }
            tokenCounter++;
        } else if (isdigit(*source)) {
            char *splittedToken = digitTokenization(&source);
            tokens[tokenCounter].type = TOKEN_DIGIT;
            tokens[tokenCounter].value = splittedToken;
            tokenCounter++;
        } else if (*source == VALUE_ASSIGNMENT) {
            tokens[tokenCounter].type = TOKEN_ASSIGNMENT;
            tokens[tokenCounter].value = VALUE_ASSIGNMENT_STRING;
            tokenCounter++;
            source++;
        }else if(*source == VALUE_PUNCTUATION){
            tokens[tokenCounter].type = TOKEN_PUNCTUATION;
            tokens[tokenCounter].value = VALUE_PUNCTUATION_STRING;
            tokenCounter++;
            source++;
        }else {
            source++;
        }
    }

    tokens[tokenCounter].type = TOKEN_EOF;
    tokens[tokenCounter].value = NULL;
    return tokens;
}
