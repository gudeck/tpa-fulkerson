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

Grafo *___copiarGrafo(Grafo *grafo) {
    Grafo *novoGrafo = criaGrafo();
    for (int i = 0; i < grafo->preenchido; ++i) {
        inserirGrafo(novoGrafo, grafo->arestas[i]);
    }
    return novoGrafo;
}

void
___buscarCaminhos(Caminho *caminhosPossiveis, Grafo *grafoOriginal, Grafo *grafoResposta, char *origem, char *destino) {
    Aresta **arestas = grafoOriginal->arestas;
    int tamanho = grafoOriginal->tamanho;
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(arestas[i]->origem, origem) == 0) {
            inserirGrafo(grafoResposta, arestas[i]);
            if (strcmp(arestas[i]->destino, destino) == 0) {
                inserirCaminho(caminhosPossiveis, ___copiarGrafo(grafoResposta));
            } else {
                ___buscarCaminhos(caminhosPossiveis, grafoOriginal, grafoResposta, arestas[i]->destino, destino);
            }
            removerGrafo(grafoResposta);
        }
    }
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
    int fluxoMaximoTotal = 0;
    for (int i = 0; i < caminho->preenchido; ++i) {
        grafoAuxiliar = caminho->registros[i];
        fluxoMaximoTotal += grafoAuxiliar->fluxoMaximo;
        mostrarGrafo(grafoAuxiliar, SIMPLIFICADO);
    }
    printf("\nFluxo Maximo Total: %d\n\n", fluxoMaximoTotal);
}

void mostrarArestaNula(Grafo *grafo, char *origem, char *destino) {
    Caminho *caminhosPossiveis = criaCaminho();
    Grafo *grafoResposta = criaGrafo();
    Grafo *grafoAuxiliar;
    int quantidadeZeros;
    ___buscarCaminhos(caminhosPossiveis, grafo, grafoResposta, origem, destino);
    printf("\nOs seguintes caminhos possuem apenas 1 centro com 0 de fluxo: \n");
    for (int i = 0; i < caminhosPossiveis->preenchido; ++i) {
        grafoAuxiliar = caminhosPossiveis->registros[i];
        quantidadeZeros = 0;
        for (int j = 0; j < grafoAuxiliar->preenchido; ++j) {
            if (grafoAuxiliar->arestas[j]->fluxoDisponivel == 0)
                quantidadeZeros++;
        }
        if (quantidadeZeros == 1)
            mostrarGrafo(grafoAuxiliar, COMPLETO);
    }
    printf("\n");
}