//
// Created by pablo on 22/01/2025.
//

#ifndef LEXER_H
#define LEXER_H

#define VALUE_DEFINITION "let"
#define VALUE_ASSIGNMENT '!'
#define VALUE_ASSIGNMENT_STRING "!"
#define VALUE_PUNCTUATION ';'
#define VALUE_PUNCTUATION_STRING ";"

typedef enum {
    TOKEN_PUNCTUATION,
    TOKEN_IDENTIFIER,
    TOKEN_DEFINITION,
    TOKEN_ASSIGNMENT,
    TOKEN_DIGIT,
    TOKEN_STRING,
    TOKEN_EOF,
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

Token *lexer(const char *source);
void free_tokens(Token *tokens);

#endif //LEXER_H
