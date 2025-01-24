//
// Created by pablo on 22/01/2025.
//

#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lexer/lexer.h"

int currentToken = 0;

Node *CreateFatherNode() {
    Node *node = calloc(1, sizeof(Node));
    node->type = PROGRAM;
    node->name = "PROGRAM";
    return node;
}

Node *GenerateEOFNode() {
    Node *node = calloc(1, sizeof(Node));
    node->type = NODE_EOF;
    node->name = "EOF";
    return node;
}


Node *generateOperatorNode(const Token *tokens, Node *children[100]) {
    int i = 0;
    int u = 0;
    Node *node = calloc(1, sizeof(Node));
    node->type = OPERATOR;
    node->name = tokens[currentToken + 1].value;
    while (tokens[currentToken].type != TOKEN_PUNCTUATION) {
        if (strcmp(tokens[currentToken].value, children[i]->name) == 0) {
            node->children[u] = children[i];
            u++;
            currentToken++;
            i = 0;
        }
        if (children[i + 1]->type == NODE_EOF) {
            currentToken++;
            i = 0;
        } else {
            i++;
        }
    }
    if (node->children[0] == NULL || node->children[1] == NULL) {
        printf("cannot operate with NULL values, maybe there is an error in the variable names\n");
        exit(1);
    }
    if (node->children[0]->typeValue == STRING_TYPE || node->children[1]->typeValue == STRING_TYPE || node->children[0]
        ->typeValue == OPERATOR_STRING_TYPE || node->children[1]->typeValue == OPERATOR_STRING_TYPE) {
        node->typeValue = STRING_TYPE;
    } else {
        if (node->children[0]->typeValue == DOUBLE_TYPE || node->children[1]->typeValue == DOUBLE_TYPE || node->children
            [0]->typeValue == OPERATOR_DOUBLE_TYPE || node->children[1]->typeValue == OPERATOR_DOUBLE_TYPE) {
            node->typeValue = DOUBLE_TYPE;
        } else {
            node->typeValue = INT_TYPE;
        }
    }
    return node;
}

Node *GenerateVariableNode(const Token *tokens, Node *children[100]) {
    Node *node = calloc(1, sizeof(Node));
    node->type = ASSIGNMENT;
    while (tokens[currentToken].type != TOKEN_PUNCTUATION && tokens[currentToken].type != TOKEN_EOF) {
        if (tokens[currentToken].type == TOKEN_IDENTIFIER) {
            node->name = tokens[currentToken].value;
        } else if (tokens[currentToken].type == TOKEN_DIGIT) {
            node->value = tokens[currentToken].value;
            if (strchr(node->value, '.') == NULL) {
                node->typeValue = INT_TYPE;
            } else {
                node->typeValue = DOUBLE_TYPE;
            }
        } else if (tokens[currentToken].type == TOKEN_STRING) {
            node->value = tokens[currentToken].value;
            node->typeValue = STRING_TYPE;
        } else if (tokens[currentToken].type == TOKEN_ASSIGNMENT && tokens[currentToken + 1].type == TOKEN_IDENTIFIER) {
            currentToken++;
            node->children[0] = generateOperatorNode(tokens, children);
            if (node->children[0]->typeValue == DOUBLE_TYPE) {
                node->typeValue = OPERATOR_DOUBLE_TYPE;
            } else if (node->children[0]->typeValue == STRING_TYPE) {
                node->typeValue = OPERATOR_STRING_TYPE;
            } else {
                node->typeValue = OPERATOR_INT_TYPE;
            }
            currentToken--;
        }
        currentToken++;
    }
    return node;
}

Node *generatePrintNode(const Token *tokens, Node *children[100]) {
    int i = 0;
    int u = 0;
    Node *node = calloc(1, sizeof(Node));
    node->type = PRINT;
    node->name = tokens[currentToken].value;
    currentToken += 2;
    char *varName = tokens[currentToken].value;
    while (tokens[currentToken].type != TOKEN_PUNCTUATION) {
        if (strcmp(tokens[currentToken].value, children[i]->name) == 0) {
            node->children[u] = children[i];
            u++;
            currentToken++;
            i = 0;
        }
        if (children[i + 1]->type == NODE_EOF) {
            currentToken++;
            i = 0;
        } else {
            i++;
        }
    }
    if (node->children[0] == NULL) {
        printf("cannot print variable \"%s\" because it is not defined\n", varName);
        exit(1);
    }
    return node;
}

Node *generateParameterNode(const Token *tokens) {
    Node *node = calloc(1, sizeof(Node));
    node->type = PARAMETER;
    node->name = tokens[currentToken].value;
    return node;
}

Node *functionNodeGenerator(const Token *tokens, Node *children[100]) {
    int i = 0;
    int u = 0;
    Node *node = calloc(1, sizeof(Node));
    node->type = FUNCTION;
    currentToken++;
    node ->name = tokens[currentToken].value;
    currentToken +=2;
    while (tokens[currentToken].type != TOKEN_PARENTHESES_CLOSE) {
        node->children[i] = generateParameterNode(tokens);
        currentToken++;
        if(tokens[currentToken].type == TOKEN_COMMA) {
            currentToken++;
        }
        i++;
    }
    currentToken += 2;
    Node **childrenFunction = ASTGenerator(tokens);
    while((*childrenFunction)->type != NODE_EOF) {
        if((*childrenFunction)->typeValue == STRING_TYPE) {
            node->typeValue = STRING_TYPE;
        } else if((*childrenFunction)->typeValue == INT_TYPE) {
            node->typeValue = INT_TYPE;
        } else if((*childrenFunction)->typeValue == DOUBLE_TYPE) {
            node->typeValue = DOUBLE_TYPE;
        } else {
            node->typeValue = NULL_TYPE;
        }
        node->children[i] = *childrenFunction;
        childrenFunction++;
        i++;
    }
    node->children[i] = GenerateEOFNode();
    return node;
}

Node *returnNodeGenerator(Token *tokens, Node *children[100]) {
    Node *node = calloc(1, sizeof(Node));
    node->type = RETURN;
    node->name = "return";
    currentToken++;
    node->value = tokens[currentToken].value;
    int i = 0;
    while (children[i]->type != NODE_EOF) {
        if (strcmp(children[i]->name, node->value) == 0) {
            if(children[i]->typeValue == DOUBLE_TYPE) {
                node->typeValue = DOUBLE_TYPE;
            } else if(children[i]->typeValue == STRING_TYPE) {
                node->typeValue = STRING_TYPE;
            } else if(children[i]->typeValue == INT_TYPE) {
                node->typeValue = INT_TYPE;
            }else {
                node->typeValue = NULL_TYPE;
            }
        }
        i++;
    }
    if(node->typeValue == NULL_TYPE) {
        printf("cannot return variable \"%s\" because it is not defined\n", node->value);
        exit(1);
    }
    return node;
}

Node **ASTGenerator(const Token *tokens) {
    int childrenCounter = 0;
    Node** children = malloc(100 * sizeof(Node));
    while (tokens[currentToken].type != TOKEN_EOF && tokens[currentToken].type != TOKEN_CURLY_BRACKETS_CLOSE) {
        if (tokens[currentToken].type == TOKEN_DEFINITION) {
            children[childrenCounter] = GenerateVariableNode(tokens, children);
            currentToken++;
            childrenCounter++;
            children[childrenCounter] = GenerateEOFNode();
        } else if (tokens[currentToken].type == TOKEN_IDENTIFIER) {
            children[childrenCounter] = generateOperatorNode(tokens, children);
            currentToken++;
            childrenCounter++;
            children[childrenCounter] = GenerateEOFNode();
        }else if(tokens[currentToken].type == TOKEN_RETURN) {
            children[childrenCounter] = returnNodeGenerator(tokens, children);
            currentToken++;
            childrenCounter++;
            children[childrenCounter] = GenerateEOFNode();
        }else if(tokens[currentToken].type == TOKEN_FUNCTION_DEFINITION) {
            children[childrenCounter] = functionNodeGenerator(tokens, children);
            currentToken++;
            childrenCounter++;
            children[childrenCounter] = GenerateEOFNode();
        } else if (tokens[currentToken].type == TOKEN_PRINT) {
            children[childrenCounter] = generatePrintNode(tokens, children);
            currentToken++;
            childrenCounter++;
            children[childrenCounter] = GenerateEOFNode();
        } else if (tokens[currentToken].type == TOKEN_PUNCTUATION) {
            currentToken++;
        }
    }
    return children;
}

Node *ASTProgramGenerator(const Token *tokens) {
    int childrenCounter = 0;
    Node *programNode = CreateFatherNode();
    Node **children = ASTGenerator(tokens);
    while((*children)->type != NODE_EOF) {
        programNode->children[childrenCounter] = *children;
        children++;
        childrenCounter++;
    }
    programNode->children[childrenCounter] = GenerateEOFNode();
    return programNode;
}
