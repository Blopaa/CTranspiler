#include <stdio.h>
#include "lexer/lexer.h"

int main(void) {
    const char *input = "let x = 10;";
    int i = 0;
    Token *tokens = lexer(input);
    while(tokens[i].type != TOKEN_EOF) {
        printf("Token type: %d, Value: %s\n", tokens[i].type, tokens[i].value);
        i++;
    }
    printf("Token type: %d, Value: %s\n", tokens[i].type, tokens[i].value);
    return 0;
}
