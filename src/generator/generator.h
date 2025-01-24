//
// Created by pablo on 23/01/2025.
//

#ifndef GENERATOR_H
#define GENERATOR_H
#include "../parser/parser.h"
#include <stdio.h>

void generateCode(const Node *node, FILE *output, int original);

#endif //GENERATOR_H
