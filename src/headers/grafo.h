//
// Created by guzuc on 09/11/2019.
//
#ifndef TPA_DIJKSTRA_GRAFO_H
#define TPA_DIJKSTRA_GRAFO_H

#include "vetor.h"

typedef struct ___grafo {
    Vetor *arestas;
} Grafo;

Grafo *criaGrafo();

void inserirGrafo(Grafo *grafo, Aresta *novaAresta);

void mostrarGrafo(Grafo *grafo);

#endif //TPA_DIJKSTRA_GRAFO_H
