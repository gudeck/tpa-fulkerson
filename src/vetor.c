//
// Created by guzuc on 09/11/2019.
//
#include <stdbool.h>
#include <stdlib.h>
#include "headers/vetor.h"
#include "headers/main.h"

Vetor *criaVetor(int tamanho) {
    Vetor *novoVetor = calloc(1, sizeof(Vetor));
    novoVetor->registros = calloc(tamanho, sizeof(Aresta *));
    novoVetor->tamanho = tamanho;
    return novoVetor;
}

bool precisaExpandir(Vetor *vetor) {
    return (vetor->tamanho - vetor->preenchido) == 0;
}

void expandeVetor(Vetor *vetor) {
    Aresta **novoArray = calloc(vetor->tamanho + 1, sizeof(Aresta *));
    for (int i = 0; i < vetor->tamanho; ++i) {
        novoArray[i] = vetor->registros[i];
    }
    vetor->registros = novoArray;
    vetor->tamanho = vetor->tamanho + 1;
}

void inserirVetor(Vetor *vetor, Aresta *novaAresta) {
    if (precisaExpandir(vetor)) expandeVetor(vetor);
    vetor->registros[vetor->preenchido++] = novaAresta;
}