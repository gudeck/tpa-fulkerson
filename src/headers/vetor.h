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
    Aresta **registros;
} Vetor;

Vetor *criaVetor(int tamanho);

void inserirVetor(Vetor *vetor, Aresta *novaAresta);

#endif //TPA_DIJKSTRA_VETOR_H
