//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <string.h>
#include "headers/arquivo.h"

int main() {
    FILE *arquivoDistancias = fopen("../distancias.txt", "r");
    FILE *arquivoFluxos = fopen("../fluxos.txt", "r");
    FILE *arquivoVeiculos = fopen("../veiculos.txt", "r");
    Grafo *grafo = preencherGrafo(arquivoDistancias, arquivoFluxos);
    Vetor *veiculos = preencherVeiculos(arquivoVeiculos);

    for (int i = 0; i < veiculos->tamanho; ++i) {
        printf("%s %f\n", veiculos->registros[i]->placa, veiculos->registros[i]->capacidade);
    }

    mostrarGrafo(grafo);

    return 0;
}

char *criaString(char *string) {
    char *novaString = calloc(strlen(string), sizeof(char));
    if (strstr(string, "\n")) string = strtok(string, "\n");
    strcpy(novaString, string);
    return novaString;
}
