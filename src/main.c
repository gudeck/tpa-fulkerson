//
// Created by guzuc on 09/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/grafo.h"
#include "headers/vetor.h"
#include "headers/fulkerson.h"

int main() {
    FILE *arquivoDistancias = fopen("../distancias.txt", "r");
    FILE *arquivoFluxos = fopen("../fluxos.txt", "r");
    FILE *arquivoVeiculos = fopen("../veiculos.txt", "r");
    char origem[100];
    char destino[100];

    printf("Entre com a origem:");
    scanf("%s", origem);
    printf("Entre com o destino:");
    scanf("%s", destino);

    Grafo *grafo = preencherGrafo(arquivoDistancias, arquivoFluxos);
    Vetor *veiculos = preencherVeiculos(arquivoVeiculos);
    Caminho *caminhos = fordFulkerson(veiculos, grafo, origem, destino);
    mostrarCaminho(caminhos);
    mostrarVeiculosNaoAlocados(veiculos);
    mostrarVeiculosInsuficientes(caminhos, veiculos);
    mostrarCargaPendente(grafo);
    mostrarArestaNula(grafo, origem, destino);

    return 0;
}

char *criaString(char *string) {
    char *novaString = calloc(strlen(string), sizeof(char));
    if (strstr(string, "\n")) string = strtok(string, "\n");
    strcpy(novaString, string);
    return novaString;
}
