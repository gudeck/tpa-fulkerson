//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <string.h>
#include "headers/arquivo.h"

int main() {
    FILE *arquivo = fopen("../distancias.txt", "r");
    Grafo *grafo = preencherGrafo(arquivo);

    mostrarGrafo(grafo);

    return 0;
}

char *criaString(char *string) {
    char *novaString = calloc(strlen(string), sizeof(char));
    if (strstr(string, "\n")) string = strtok(string, "\n");
    strcpy(novaString, string);
    return novaString;
}
