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
            if(node->typeValue == INT_TYPE || node->typeValue == DOUBLE_TYPE) {
                char *type = node->typeValue == INT_TYPE ? "int" : "double";
                fprintf(output, "\t%s %s = %s;\n",type, node->name, node->value);
            }else if(node->typeValue == STRING_TYPE) {
                fprintf(output, "\tchar *%s = \"%s\";\n", node->name, node->value);
            }else if (node->typeValue == OPERATOR_INT_TYPE || node->typeValue == OPERATOR_DOUBLE_TYPE) {
                char *type = node->typeValue == OPERATOR_INT_TYPE ? "int" : "double";
                fprintf(output, "\t%s %s = ",type, node->name);
                generateCode(node->children[0], output);
            }
            break;
        case OPERATOR:
            fprintf(output, "%s %s %s;\n", node->children[0]->name, node->name, node->children[1]->name);
            break;
    }
}
