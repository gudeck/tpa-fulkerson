//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include "headers/grafo.h"

Grafo *criaGrafo() {
    Grafo *novoGrafo = calloc(1, sizeof(Grafo));
    novoGrafo->arestas = criaVetor(1);
    return novoGrafo;
}

void inserirGrafo(Grafo *grafo, Aresta *novaAresta) {
    inserirVetor(grafo->arestas, novaAresta);
}

void mostrarGrafo(Grafo *grafo) {
    printf("\n");
    for (int i = 0; i < grafo->arestas->tamanho; ++i) {
        printf("%s -> %s = %f\n", grafo->arestas->registros[i]->origem,
               grafo->arestas->registros[i]->destino,
               grafo->arestas->registros[i]->distancia);
    }
    printf("\n");
}

