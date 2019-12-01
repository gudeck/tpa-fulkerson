//
// Created by 2017122760013 on 28/11/2019.
//

#ifndef TPA_FULKERSON_FULKERSON_H
#define TPA_FULKERSON_FULKERSON_H

#include "grafo.h"
#include "caminho.h"
#include "vetor.h"

Caminho *fordFulkerson(Grafo *grafo, char *origem, char *destino);

void alocarVeiculos(Caminho *caminhos, Vetor *veiculos);

#endif //TPA_FULKERSON_FULKERSON_H
