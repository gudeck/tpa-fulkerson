//
// Created by 2017122760013 on 28/11/2019.
//

#include <string.h>
#include <stdio.h>
#include "headers/fulkerson.h"
#include "headers/caminho.h"

/*
 * Fazer percorrer caminho da origem até destino
 * Diminuir o menor fluxo do caminho dos fluxos de cada vértice desse caminho
 */

Grafo *___percorreGrafo(Grafo *grafoOriginal, char *origem, char *destino) {
    Aresta **arestas = grafoOriginal->arestas;
    int tamanho = grafoOriginal->tamanho;

    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(arestas[i]->origem, origem) == 0) {
            printf("%s -> %s\n", arestas[i]->origem, arestas[i]->destino);
            if (strcmp(arestas[i]->destino, destino) == 0) {
                printf("\n");
            } else {
                ___percorreGrafo(grafoOriginal, arestas[i]->destino, destino);
            }
        }
    }
    return NULL;
}

Caminho *___buscarCaminhos(Grafo *grafo, char *origem, char *destino) {
    Caminho *caminhosPossiveis = criaCaminho();
    ___percorreGrafo(grafo, origem, destino);
    return NULL;
}
