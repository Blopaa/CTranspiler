//
// Created by pablo on 23/01/2025.
//

#include "generator.h"

#include <stdlib.h>
#include <string.h>
int tempVars = 0;

void generateCode(const Node *node, FILE *output, int original) {
    if (original == 1) {
        fprintf(output, "#include <stdio.h>\n#include <stdlib.h>\n\n");
        int u = 0;
        while (node->children[u]->type != NODE_EOF) {
            if (node->children[u]->type == FUNCTION) {
                char *functionReturnType;
                if(node->children[u]->typeValue == INT_TYPE) {
                    functionReturnType = "int";
                } else if(node->children[u]->typeValue == DOUBLE_TYPE) {
                    functionReturnType = "double";
                } else if (node->children[u]->typeValue == STRING_TYPE) {
                    functionReturnType = "char* ";
                }else {
                    functionReturnType = "void";
                }
                fprintf(output, "%s %s(",functionReturnType, node->children[u]->name);
                int x = 0;
                while (node->children[u]->children[x]->type == PARAMETER) {
                    fprintf(output, "%s", node->children[u]->children[x]->name);
                    if (node->children[u]->children[x + 1]->type == PARAMETER) {
                        fprintf(output, ",");
                    }
                    x++;
                }
                fprintf(output, "){\n");
                while (node->children[u]->children[x]->type != NODE_EOF) {
                    generateCode(node->children[u]->children[x], output, 0);
                    x++;
                }
                fprintf(output, "}\n\n");
            }
            u++;
        }
    }
    int i = 0;
    if (node == NULL) return;
    switch (node->type) {
        case PROGRAM:
            fprintf(output, "int main(void){\n");
            while (node->children[i]->type != NODE_EOF) {
                generateCode(node->children[i], output, 0);
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
                    char firstOT;
                    char secondOT;
                    if (node->children[0]->children[0]->typeValue == INT_TYPE || node->children[0]->children[0]->
                        typeValue == OPERATOR_INT_TYPE) {
                        firstOT = 'd';
                    } else if (node->children[0]->children[0]->typeValue == STRING_TYPE || node->children[0]->children[
                                   0]->typeValue == OPERATOR_STRING_TYPE) {
                        firstOT = 's';
                    } else {
                        firstOT = 'f';
                    }
                    if (node->children[0]->children[1]->typeValue == INT_TYPE || node->children[0]->children[1]->
                        typeValue == OPERATOR_INT_TYPE) {
                        secondOT = 'd';
                    } else if (node->children[0]->children[1]->typeValue == STRING_TYPE || node->children[0]->children[
                                   1]->typeValue == OPERATOR_STRING_TYPE) {
                        secondOT = 's';
                    } else {
                        secondOT = 'f';
                    }
                    fprintf(output, "\tint size%d = snprintf(NULL, 0, \"%%%c%%%c\", %s, %s) + 1;\n", tempVars,
                            firstOT, secondOT,
                            node->children[0]->children[0]->name, node->children[0]->children[1]->name);
                    fprintf(output, "\t%s%s = malloc(size%d);\n", type, node->name, tempVars);
                    fprintf(output, "\tsprintf(%s,\"%%%c%%%c\", %s, %s);\n", node->name, firstOT, secondOT,
                            node->children[0]->children[0]->name, node->children[0]->children[1]->name);
                    tempVars++;
                } else {
                    if (node->typeValue == OPERATOR_INT_TYPE) {
                        type = "int ";
                    } else {
                        type = "double ";
                    }
                    fprintf(output, "\t%s%s = ", type, node->name);
                    generateCode(node->children[0], output, 0);
                }
            }
            break;
        case OPERATOR:
            fprintf(output, "%s %s %s;\n", node->children[0]->name, node->name, node->children[1]->name);
            break;
        case RETURN:
            fprintf(output, "\treturn %s;\n", node->value);
            break;
        case PRINT:
            fprintf(output, "\tprintf(\"%%s\", %s);\n", node->children[0]->name);
            break;
        case FUNCTION:
            break;
        default:
            printf("an error ocurred while code generation\n");
            exit(1);
    }
}
