//
// Created by pablo on 23/01/2025.
//

#include "generator.h"

#include <stdlib.h>
#include <string.h>
int tempVars = 0;

void generateCode(const Node *node, FILE *output) {
    int i = 0;
    if (node == NULL) return;
    switch (node->type) {
        case PROGRAM:
            fprintf(output, "#include <stdio.h>\n#include <stdlib.h>\n\nint main(void){\n");
            while (node->children[i]->type != NODE_EOF) {
                generateCode(node->children[i], output);
                i++;
            }
            fprintf(output, "\n\treturn 0;\n}\n");
            break;
        case ASSIGNMENT:
            if (node->typeValue == INT_TYPE || node->typeValue == DOUBLE_TYPE) {
                char *type = node->typeValue == INT_TYPE ? "int" : "double";
                fprintf(output, "\t%s %s = %s;\n", type, node->name, node->value);
            } else if (node->typeValue == STRING_TYPE) {
                fprintf(output, "\tchar *%s = \"%s\";\n", node->name, node->value);
            } else if (node->typeValue == OPERATOR_INT_TYPE || node->typeValue == OPERATOR_DOUBLE_TYPE || node->
                       typeValue == OPERATOR_STRING_TYPE) {
                char *type;
                if (node->typeValue == OPERATOR_STRING_TYPE) {
                    type = "char *";
                    char operationType;
                    if (node->children[0]->children[0]->typeValue == INT_TYPE || node->children[0]->children[0]->
                        typeValue == OPERATOR_INT_TYPE) {
                        operationType = 'd';
                    } else {
                        operationType = 'f';
                    }
                    fprintf(output, "\tint size%d = snprintf(NULL, 0, \"%%%c%%s\", %s, %s) + 1;\n", tempVars,
                            operationType,
                            node->children[0]->children[0]->name, node->children[0]->children[1]->name);
                    fprintf(output, "\t%s%s = malloc(size%d);\n", type, node->name, tempVars);
                    fprintf(output, "\tsprintf(%s,\"%%%c%%s\", %s, %s);\n", node->name, operationType,
                            node->children[0]->children[0]->name, node->children[0]->children[1]->name);
                    tempVars++;
                } else {
                    if (node->typeValue == OPERATOR_INT_TYPE) {
                        type = "int ";
                    } else {
                        type = "double ";
                    }
                    fprintf(output, "\t%s%s = ", type, node->name);
                    generateCode(node->children[0], output);
                }
            }
            break;
        case OPERATOR:
            fprintf(output, "%s %s %s;\n", node->children[0]->name, node->name, node->children[1]->name);
            break;
        case PRINT:
            fprintf(output, "\tprintf(\"%%s\", %s);\n", node->children[0]->name);
            break;
        default:
            printf("an error ocurred while code generation\n");
            exit(1);
    }
}
