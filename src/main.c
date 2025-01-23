#include <stdio.h>
#include <stdlib.h>
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "generator/generator.h"

int main(void) {
    FILE *outputFile;
    FILE *inputFile;

    outputFile = fopen("src/output.c", "w");
    inputFile = fopen("src/input.zk", "rb");

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
    inputText[fileSize] = '\0';

    printf("%s\n", inputText);

    if(outputFile != NULL) {
        Token *tokens = lexer(inputText);
        Node *nodes = ASTGenerator(tokens);
        generateCode(nodes, outputFile);
    }
    fclose( outputFile);

    return 0;

}