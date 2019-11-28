//
// Created by 2017122760013 on 28/11/2019.
//

#include <stdlib.h>
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

void inserirCaminho(Caminho *caminho, Grafo *novoRegistro) {
    if (precisaExpandirCaminho(caminho)) expandeCaminho(caminho);
    caminho->registros[caminho->preenchido++] = novoRegistro;

}
