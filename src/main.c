//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <string.h>
#include "headers/arquivo.h"

int main() {
    FILE *arquivoDistancias = fopen("../distancias.txt", "r");
    FILE *arquivoFluxos = fopen("../fluxos.txt", "r");
    Grafo *grafo = preencherGrafo(arquivoDistancias, arquivoFluxos);

    mostrarGrafo(grafo);

    return 0;
}

char *criaString(char *string) {
    char *novaString = calloc(strlen(string), sizeof(char));
    if (strstr(string, "\n")) string = strtok(string, "\n");
    strcpy(novaString, string);
    return novaString;
}
