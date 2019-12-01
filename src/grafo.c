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
    for (int i = 0; i < grafo->preenchido; ++i) {
        novoArray[i] = grafo->arestas[i];
    }
    grafo->arestas = novoArray;
    grafo->tamanho = grafo->tamanho + 1;
}

void inserirGrafo(Grafo *grafo, Aresta *novaAresta) {
    if (precisaExpandirGrafo(grafo)) expandeGrafo(grafo);
    grafo->arestas[grafo->preenchido++] = novaAresta;
}

bool precisaEncolherGrafo(Grafo *grafo) {
    return (grafo->tamanho - grafo->preenchido) > 0;
}

void encolheGrafo(Grafo *grafo) {
    Aresta **novoArray = calloc(--grafo->tamanho, sizeof(Aresta *));
    for (int i = 0; i < grafo->preenchido; ++i) {
        novoArray[i] = grafo->arestas[i];
    }
    grafo->arestas = novoArray;
}

void removerGrafo(Grafo *grafo) {
    if (precisaEncolherGrafo(grafo))encolheGrafo(grafo);
    grafo->arestas[grafo->preenchido--] = NULL;
}

int ___calcularDistancia(Grafo *grafo) {
    int distanciaTotal = 0;
    for (int i = 0; i < grafo->preenchido; ++i) {
        distanciaTotal += grafo->arestas[i]->distancia;
    }
    return distanciaTotal;
}

void mostrarGrafo(Grafo *grafo) {
    printf("\n");
    grafo->veiculoAlocado == NULL ?
    printf("Fluxo Maximo: %d Distancia: %d\n", grafo->fluxoMaximo, ___calcularDistancia(grafo)) :
    printf("Fluxo Maximo: %d Distancia: %d\nPlaca: %s Capacidade: %d\n",
           grafo->fluxoMaximo,
           ___calcularDistancia(grafo),
           grafo->veiculoAlocado->placa,
           grafo->veiculoAlocado->capacidade);
    for (int i = 0; i < grafo->preenchido; ++i) {
        printf("%s -> %s = D: %d F: %d\n", grafo->arestas[i]->origem,
               grafo->arestas[i]->destino,
               grafo->arestas[i]->distancia,
               grafo->arestas[i]->fluxoDisponivel);
    }
    printf("\n");
}

void mostrarCargaPendente(Grafo *grafo) {
    printf("\nArestas com carga pendente:\n");
    for (int i = 0; i < grafo->preenchido; ++i) {
        if (grafo->arestas[i]->fluxoDisponivel > 0)
            printf("%s -> %s = Carga: %d\n",
                   grafo->arestas[i]->origem,
                   grafo->arestas[i]->destino,
                   grafo->arestas[i]->fluxoDisponivel);
    }
    printf("\n");
}