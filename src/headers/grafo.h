//
// Created by guzuc on 09/11/2019.
//
#ifndef TPA_DIJKSTRA_VETOR_H
#define TPA_DIJKSTRA_VETOR_H

#include <stdbool.h>
#include "aresta.h"

typedef struct ___vetor {
    int tamanho;
    int preenchido;
    Aresta **arestas;
} Grafo;

Grafo *criaGrafo();

void inserirGrafo(Grafo *vetor, Aresta *novaAresta);

void mostrarGrafo(Grafo *grafo);

#endif //TPA_DIJKSTRA_VETOR_H
