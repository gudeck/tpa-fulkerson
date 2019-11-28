//
// Created by 2017122760013 on 28/11/2019.
//

#ifndef TPA_FULKERSON_CAMINHO_H
#define TPA_FULKERSON_CAMINHO_H

#include "grafo.h"

typedef struct ___caminho {
    int tamanho;
    int preenchido;
    Grafo **registros;
} Caminho;

Caminho *criaCaminho();

void inserirCaminho(Caminho *caminho, Grafo *novoRegistro);

#endif //TPA_FULKERSON_CAMINHO_H
