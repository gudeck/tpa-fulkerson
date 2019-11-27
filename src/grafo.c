//
// Created by guzuc on 09/11/2019.
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/grafo.h"

Grafo *criaGrafo() {
    int tamanho = 1;
    Grafo *novoVetor = calloc(1, sizeof(Grafo));
    novoVetor->arestas = calloc(tamanho, sizeof(Aresta *));
    novoVetor->tamanho = tamanho;
    return novoVetor;
}

bool precisaExpandir(Grafo *vetor) {
    return (vetor->tamanho - vetor->preenchido) == 0;
}

void expandeVetor(Grafo *vetor) {
    Aresta **novoArray = calloc(vetor->tamanho + 1, sizeof(Aresta *));
    for (int i = 0; i < vetor->tamanho; ++i) {
        novoArray[i] = vetor->arestas[i];
    }
    vetor->arestas = novoArray;
    vetor->tamanho = vetor->tamanho + 1;
}

void inserirGrafo(Grafo *vetor, Aresta *novaAresta) {
    if (precisaExpandir(vetor)) expandeVetor(vetor);
    vetor->arestas[vetor->preenchido++] = novaAresta;
}

void mostrarGrafo(Grafo *grafo) {
    printf("\n");
    for (int i = 0; i < grafo->tamanho; ++i) {
        printf("%s -> %s = D: %.0f F: %.0f\n", grafo->arestas[i]->origem,
               grafo->arestas[i]->destino,
               grafo->arestas[i]->distancia,
               grafo->arestas[i]->fluxoDisponivel);
    }
    printf("\n");
}