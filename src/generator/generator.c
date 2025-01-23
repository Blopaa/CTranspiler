//
// Created by pablo on 23/01/2025.
//

#include "generator.h"

#include <string.h>

void generateCode(Node *node, FILE *output) {
    int i = 0;
    if (node == NULL) return;
    switch (node->type) {
        case PROGRAM:
            fprintf(output, "#include <stdio.h>\n\nint main(void){\n");
            while(node->children[i]->type!=NODE_EOF) {
                generateCode(node->children[i], output);
                i++;
            }
            fprintf(output, "\n\treturn 0;\n}\n");
            break;
        case ASSIGNMENT:
            if(node->typeValue == NUMBER_TYPE) {
                char *type = strchr(node->value, '.') == NULL ? "int" : "double";
                fprintf(output, "\t%s %s = %s;\n",type, node->name, node->value);
            }else if(node->typeValue == STRING_TYPE) {
                fprintf(output, "\tchar *%s = \"%s\";\n", node->name, node->value);
            }
            break;
    }
}
