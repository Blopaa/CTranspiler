#include <stdio.h>
#include <stdlib.h>
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "generator/generator.h"

int main(void) {
    FILE *outputFile;
    FILE *inputFile;

    outputFile = fopen("src/output.c", "w");
    inputFile = fopen("src/input.zk", "r");

    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    char *inputText = malloc(fileSize + 1);
    if (inputText == NULL) {
        perror("Error al reservar memoria");
        fclose(inputFile);
        return 1;
    }

    fread(inputText, 1, fileSize, inputFile);
    inputText[fileSize-1] = '\0';

    if(outputFile != NULL) {
        Token *tokens = lexer(inputText);
        Node *nodes = ASTGenerator(tokens);
        generateCode(nodes, outputFile);
    }
    fclose( outputFile);

    return 0;

}




/**
*  int i = 0;
    Token *tokens = lexer(input);
    while(tokens[i].type != TOKEN_EOF) {
        printf("Token type: %d, Value: %s\n", tokens[i].type, tokens[i].value);
        i++;
    }
    printf("Token type: %d, Value: %s\n", tokens[i].type, tokens[i].value);
    Node *nodes = ASTGenerator(tokens);
    printf("Node type: %d, Name: %s, Value: %s\n", nodes->type, nodes->name, nodes->value);
    printf("children: \n");
    int u = 0;
    while(nodes->children[u] != NULL && nodes->children[u]->type != EOF) {
        printf("Node type: %d, Name: %s, Value: %s\n", nodes->children[u]->type, nodes->children[u]->name, nodes->children[u]->value);
        u++;
    }

 */