//
// Created by pablo on 22/01/2025.
//

#ifndef LEXER_H
#define LEXER_H

#define VALUE_DEFINITION "def"
#define VALUE_FUNCTION_DEFINITION "func"
#define VALUE_PRINT "print"
#define VALUE_ASSIGNMENT '!'
#define VALUE_ASSIGNMENT_STRING "!"
#define VALUE_PUNCTUATION ';'
#define VALUE_PUNCTUATION_STRING ";"
#define VALE_PARENTHESES_OPEN '('
#define VALE_PARENTHESES_CLOSE ')'
#define VALUE_COMMA ','
#define VALUE_CURLY_BRACKETS_OPEN '{'
#define VALUE_CURLY_BRACKETS_CLOSE '}'
#define VALUE_RETURN "ret"

typedef enum {
    TOKEN_RETURN,
    TOKEN_FUNCTION_DEFINITION,
    TOKEN_CURLY_BRACKETS_OPEN,
    TOKEN_CURLY_BRACKETS_CLOSE,
    TOKEN_COMMA,
    TOKEN_PARENTHESES_OPEN,
    TOKEN_PARENTHESES_CLOSE,
    TOKEN_PRINT,
    TOKEN_PUNCTUATION,
    TOKEN_OPERATOR,
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
