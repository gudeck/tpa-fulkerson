//
// Created by guzuc on 09/11/2019.
//

#include <stdlib.h>
#include "headers/arquivo.h"

void verificaArquivo(FILE *arquivo) {
    if (!arquivo) {
        printf("\nFalha ao abrir o arquivo!\n");
        exit(0);
    }
}
