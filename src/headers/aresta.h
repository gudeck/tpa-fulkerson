//
// Created by guzuc on 09/11/2019.
//
#ifndef TPA_DIJKSTRA_ARESTA_H
#define TPA_DIJKSTRA_ARESTA_H

#include <stdbool.h>

typedef struct ___aresta {
    char *origem;
    char *destino;
    int distancia;
    int fluxoDisponivel;
} Aresta;

Aresta *criaAresta(char *origem, char *destino, char *distancia, char *fluxoDisponivel);

#endif //TPA_DIJKSTRA_ARESTA_H
