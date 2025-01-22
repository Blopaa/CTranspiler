#include <stdio.h>
#include "lexer/lexer.h"
#include "parser/parser.h"

int main(void) {
    const char *input = "let b = 13;let a = 12;";
    int i = 0;
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

    return 0;
}
