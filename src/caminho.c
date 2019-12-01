//
// Created by 2017122760013 on 28/11/2019.
//

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "headers/caminho.h"
#include "headers/vetor.h"

bool ___precisaExpandirCaminho(Caminho *caminho) {
    return (caminho->tamanho - caminho->preenchido) == 0;
}

void ___expandeCaminho(Caminho *caminho) {
    Grafo **novoArray = calloc(caminho->tamanho + 1, sizeof(Grafo *));
    for (int i = 0; i < caminho->preenchido; ++i) {
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

void inserirCaminho(Caminho *caminho, Grafo *novoRegistro) {
    if (___precisaExpandirCaminho(caminho)) ___expandeCaminho(caminho);
    caminho->registros[caminho->preenchido++] = novoRegistro;
    caminho->fluxoMaximo += novoRegistro->fluxoMaximo;
}

void mostrarCaminho(Caminho *caminho) {
    Grafo *grafoAuxiliar;
    for (int i = 0; i < caminho->preenchido; ++i) {
        grafoAuxiliar = caminho->registros[i];
        mostrarGrafo(grafoAuxiliar);
    }
}