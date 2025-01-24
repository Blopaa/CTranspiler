//
// Created by pablo on 22/01/2025.
//

#ifndef PARSER_H
#define PARSER_H
#include "../lexer/lexer.h"

typedef enum {
    INT_TYPE,
    DOUBLE_TYPE,
    STRING_TYPE,
    OPERATOR_INT_TYPE,
    OPERATOR_DOUBLE_TYPE,
    OPERATOR_STRING_TYPE
} TypeValue;

typedef enum {
    OPERATOR,
    PRINT,
    PROGRAM,
    LITERAL,
    ASSIGNMENT,
    NODE_EOF
} NodeType;

struct Node{
    NodeType type;
    TypeValue typeValue;
    char *name;
    char *value;
    struct Node *children[100];
};

typedef struct Node Node;

Node *ASTGenerator(const Token *tokens);

#endif //PARSER_H
