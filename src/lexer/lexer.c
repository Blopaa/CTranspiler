//
// Created by pablo on 22/01/2025.
//

#include "lexer.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token *tokens;
int tokenCounter;

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

char *stringTokenization(const char **raw) {
    char buffer[100];
    int i = 0;
    (*raw)++;
    while (**raw != '\"') {
        buffer[i++] = **raw;
        (*raw)++;
    }
    (*raw)++;
    buffer[i] = '\0';
    return strdup(buffer);
}

void assingToken(TokenType type, const char *value) {
    tokens[tokenCounter].type = type;
    tokens[tokenCounter].value = value;
}

Token *lexer(const char *source) {
    tokens = calloc(100, sizeof(Token));
    tokenCounter = 0;
    while (*source != '\0') {
        while (isspace(*source) || *source == '\n') {
            source++;
        }

        if (isalpha(*source)) {
            char *splittedToken = tokenization(&source);
            if (strcmp(splittedToken,VALUE_DEFINITION) == 0) {
                assingToken(TOKEN_DEFINITION, VALUE_DEFINITION);
            } else {
                assingToken(TOKEN_IDENTIFIER, splittedToken);
            }
            tokenCounter++;
        }else if(*source == '\"') {
            char *stringToken = stringTokenization(&source);
            assingToken(TOKEN_STRING, stringToken);
            tokenCounter++;
        } else if (isdigit(*source)) {
            char *splittedToken = digitTokenization(&source);
            assingToken(TOKEN_DIGIT, splittedToken);
            tokenCounter++;
        } else if (*source == VALUE_ASSIGNMENT) {
            assingToken(TOKEN_ASSIGNMENT, VALUE_ASSIGNMENT_STRING);
            tokenCounter++;
            source++;
        }else if(*source == VALUE_PUNCTUATION){
            assingToken(TOKEN_PUNCTUATION, VALUE_PUNCTUATION_STRING);
            tokenCounter++;
            source++;
        }else {
            source++;
        }
    }

    tokens[tokenCounter].type = TOKEN_EOF;
    return tokens;
}
