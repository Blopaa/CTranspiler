//
// Created by pablo on 22/01/2025.
//

#include "parser.h"

#include <stdlib.h>

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

Node *GenerateVariableNode(const Token *tokens) {
    Node *node = calloc(1, sizeof(Node));
    node->type = ASSIGNMENT;
    while(tokens[currentToken].type != TOKEN_PUNCTUATION) {
        if(tokens[currentToken].type == TOKEN_IDENTIFIER) {
            node->name = tokens[currentToken].value;
        }else if(tokens[currentToken].type == TOKEN_DIGIT) {
            node->value = tokens[currentToken].value;
            node->typeValue = NUMBER_TYPE;
        }else if(tokens[currentToken].type == TOKEN_STRING) {
            node->value = tokens[currentToken].value;
            node->typeValue = STRING_TYPE;
        }
        currentToken++;
    }
    return node;
}

Node *ASTGenerator(const Token *tokens) {
    int childrenCounter = 0;
    Node *programNode = CreateFatherNode();
    while (tokens[currentToken].type != TOKEN_EOF) {
        if(tokens[currentToken].type == TOKEN_DEFINITION) {
            programNode->children[childrenCounter] = GenerateVariableNode(tokens);
        }
        currentToken++;
        childrenCounter++;
    }
    programNode->children[childrenCounter]= GenerateEOFNode();

    return programNode;
}