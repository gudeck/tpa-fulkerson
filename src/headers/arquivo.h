//
// Created by guzuc on 09/11/2019.
//
#ifndef TPA_DIJKSTRA_ARQUIVO_H
#define TPA_DIJKSTRA_ARQUIVO_H

#include <stdio.h>
#include "grafo.h"
#include "vetor.h"

Grafo *preencherGrafo(FILE *arquivoDistancias, FILE *arquivoFluxos);

Vetor *preencherVeiculos(FILE *arquivoVeiculos);

#endif //TPA_DIJKSTRA_ARQUIVO_H
