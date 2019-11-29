//
// Created by 2017122760013 on 28/11/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "headers/caminho.h"

bool precisaExpandirCaminho(Caminho *caminho) {
    return (caminho->tamanho - caminho->preenchido) == 0;
}

void expandeCaminho(Caminho *caminho) {
    Grafo **novoArray = calloc(caminho->tamanho + 1, sizeof(Grafo *));
    for (int i = 0; i < caminho->tamanho; ++i) {
        novoArray[i] = caminho->registros[i];
    }
    caminho->registros = novoArray;
    caminho->tamanho = caminho->tamanho + 1;
}


Caminho *criaCaminho() {
    int tamanho = 1;
    Caminho *novoCaminho = calloc(1, sizeof(Caminho));
    novoCaminho->registros = calloc(tamanho, sizeof(Grafo *));
    novoCaminho->tamanho = tamanho;
    return novoCaminho;
}

Grafo *___copiaGrafo(Grafo *grafo) {
    Grafo *novoGrafo = criaGrafo();

    novoGrafo->fluxoMaximo = grafo->fluxoMaximo;
    for (int i = 0; i < grafo->tamanho; ++i) {
        inserirGrafo(novoGrafo, grafo->arestas[i]);
    }

    return novoGrafo;
}

bool ___jaAdicionado(Caminho *caminho, Grafo *grafo) {
    Grafo *grafoAuxiliar;
    for (int i = 0; i < caminho->tamanho; ++i) {
        grafoAuxiliar = caminho->registros[i];
        if (grafoAuxiliar == NULL) continue;
        for (int j = 0; j < grafo->tamanho; ++j) {
            if (grafo->arestas[j] != grafoAuxiliar->arestas[j]) return true;
        }
    }
    return false;
}

void inserirCaminho(Caminho *caminho, Grafo *novoRegistro) {
    if (precisaExpandirCaminho(caminho)) expandeCaminho(caminho);
//    if (!___jaAdicionado(caminho, novoRegistro))
    caminho->registros[caminho->preenchido++] = ___copiaGrafo(novoRegistro);
    caminho->fluxoMaximo += novoRegistro->fluxoMaximo;
}

void mostrarCaminho(Caminho *caminho) {
    Grafo *grafoAuxiliar;
    for (int i = 0; i < caminho->tamanho; ++i) {
        grafoAuxiliar = caminho->registros[i];
        mostrarGrafo(grafoAuxiliar);
    }
}
