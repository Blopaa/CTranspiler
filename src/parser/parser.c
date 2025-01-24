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


Node *generateOperatorNode(const Token *tokens, Node *children[10]) {
    int i = 0;
    int u = 0;
    Node *node = calloc(1, sizeof(Node));
    node->type = OPERATOR;
    node->name = tokens[currentToken + 1].value;
    while (tokens[currentToken].type != TOKEN_PUNCTUATION) {
        char *tok = tokens[currentToken].value;
        char *name = children[i]->name;
        if (strcmp(tok, name) == 0) {
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
    if (node->children[0]->typeValue == STRING_TYPE || node->children[1]->typeValue == STRING_TYPE) {
        node->typeValue = STRING_TYPE;
    } else {
        if (node->children[0]->typeValue == DOUBLE_TYPE || node->children[1]->typeValue == DOUBLE_TYPE) {
            node->typeValue = DOUBLE_TYPE;
        } else {
            node->typeValue = INT_TYPE;
        }
    }
    return node;
}

Node *GenerateVariableNode(const Token *tokens, Node *children[10]) {
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


Node *ASTGenerator(const Token *tokens) {
    int childrenCounter = 0;
    Node *programNode = CreateFatherNode();
    while (tokens[currentToken].type != TOKEN_EOF) {
        if (tokens[currentToken].type == TOKEN_DEFINITION) {
            programNode->children[childrenCounter] = GenerateVariableNode(tokens, programNode->children);
            currentToken++;
            childrenCounter++;
            programNode->children[childrenCounter] = GenerateEOFNode();
        } else if (tokens[currentToken].type == TOKEN_IDENTIFIER) {
            programNode->children[childrenCounter] = generateOperatorNode(tokens, programNode->children);
            currentToken++;
            childrenCounter++;
            programNode->children[childrenCounter] = GenerateEOFNode();
        } else if (tokens[currentToken].type == TOKEN_PUNCTUATION) {
            currentToken++;
        }
    }

    return programNode;
}
