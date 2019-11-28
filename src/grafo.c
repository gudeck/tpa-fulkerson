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

bool precisaExpandirGrafo(Grafo *grafo) {
    return (grafo->tamanho - grafo->preenchido) == 0;
}

void expandeGrafo(Grafo *grafo) {
    Aresta **novoArray = calloc(grafo->tamanho + 1, sizeof(Aresta *));
    for (int i = 0; i < grafo->tamanho; ++i) {
        novoArray[i] = grafo->arestas[i];
    }
    grafo->arestas = novoArray;
    grafo->tamanho = grafo->tamanho + 1;
}

void inserirGrafo(Grafo *grafo, Aresta *novaAresta) {
    if (precisaExpandirGrafo(grafo)) expandeGrafo(grafo);
    grafo->arestas[grafo->preenchido++] = novaAresta;
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

void swap(Grafo *grafo, int menor, int maior) {
    Aresta *aux = grafo->arestas[menor];
    grafo->arestas[menor] = grafo->arestas[maior];
    grafo->arestas[maior] = aux;
}

void ___bubbleSort(Grafo *grafo, bool (*verificacao)(Grafo *, int)) {
    int limite = grafo->tamanho - 1;
    int novoLimite;
    while (limite != -1) {
        novoLimite = -1;
        for (int i = 0; i != limite; i++) {
            if (verificacao(grafo, i)) {
                swap(grafo, i, i + 1);
                novoLimite = i;
            }
        }
        limite = novoLimite;
    }
}