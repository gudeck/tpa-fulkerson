//
// Created by 2017122760013 on 28/11/2019.
//

#include <string.h>
#include <stdio.h>
#include <math.h>
#include "headers/fulkerson.h"
#include "headers/caminho.h"

double ___encontrarMenorCapacidade(Grafo *grafo) {
    double menor = INFINITY;
    for (int i = 0; i < grafo->tamanho; ++i) {
        if (grafo->arestas[i]->fluxoDisponivel < menor) menor = grafo->arestas[i]->fluxoDisponivel;
    }
    return menor;
}

void ___subtrairCapacidades(Grafo *grafo) {
    double menorCapacidade = ___encontrarMenorCapacidade(grafo);
    grafo->fluxoMaximo = menorCapacidade;
    for (int i = 0; i < grafo->tamanho; ++i) {
        grafo->arestas[i]->fluxoDisponivel -= menorCapacidade;
    }
}

void
___percorreGrafo(Caminho *caminhosPossiveis, Grafo *grafoOriginal, Grafo *grafoResposta, char *origem, char *destino) {
    Aresta **arestas = grafoOriginal->arestas;
    int tamanho = grafoOriginal->tamanho;
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(arestas[i]->origem, origem) == 0) {
            if (arestas[i]->fluxoDisponivel == 0) continue;
            inserirGrafo(grafoResposta, arestas[i]);
            if (strcmp(arestas[i]->destino, destino) == 0) {
                ___subtrairCapacidades(grafoResposta);
                inserirCaminho(caminhosPossiveis, grafoResposta);
            } else {
                ___percorreGrafo(caminhosPossiveis, grafoOriginal, grafoResposta, arestas[i]->destino, destino);
            }
            removerGrafo(grafoResposta);
        }
    }
}

Caminho *___limparCaminhos(Caminho *caminhos) {
    Caminho *novoCaminho = criaCaminho();
    for (int i = 0; i < caminhos->tamanho; ++i) {
        if (caminhos->registros[i]->fluxoMaximo != 0)
            inserirCaminho(novoCaminho, caminhos->registros[i]);
    }
    return novoCaminho;
}

Caminho *___buscarCaminhos(Grafo *grafo, char *origem, char *destino) {
    Caminho *caminhosPossiveis = criaCaminho();
    Grafo *grafoResposta = criaGrafo();
    ___percorreGrafo(caminhosPossiveis, grafo, grafoResposta, origem, destino);
    return ___limparCaminhos(caminhosPossiveis);
}
