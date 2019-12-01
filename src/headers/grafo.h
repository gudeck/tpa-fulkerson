//
// Created by guzuc on 09/11/2019.
//
#ifndef TPA_DIJKSTRA_VETOR_H
#define TPA_DIJKSTRA_VETOR_H

#include <stdbool.h>
#include "aresta.h"
#include "veiculo.h"

typedef struct ___grafo {
    int tamanho;
    int preenchido;
    int fluxoMaximo;
    Veiculo *veiculoAlocado;
    Aresta **arestas;
} Grafo;

Grafo *criaGrafo();

void inserirGrafo(Grafo *grafo, Aresta *novaAresta);

void removerGrafo(Grafo *grafo);

void mostrarGrafo(Grafo *grafo);

#endif //TPA_DIJKSTRA_VETOR_H
