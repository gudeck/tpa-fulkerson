//
// Created by 2017122760013 on 28/11/2019.
//

#include <string.h>
#include <limits.h>
#include "headers/fulkerson.h"

int ___encontrarMenorCapacidade(Grafo *grafo) {
    int menor = INT_MAX;
    for (int i = 0; i < grafo->preenchido; ++i) {
        if (grafo->arestas[i]->fluxoDisponivel < menor) menor = grafo->arestas[i]->fluxoDisponivel;
    }
    return menor;
}

void ___subtrairCapacidades(Grafo *grafo) {
    int menorCapacidade = ___encontrarMenorCapacidade(grafo);
    grafo->fluxoMaximo = menorCapacidade;
    for (int i = 0; i < grafo->preenchido; ++i) {
        grafo->arestas[i]->fluxoDisponivel -= menorCapacidade;
    }
}

Grafo *___percorreGrafo(Grafo *grafoOriginal, Grafo *grafoResposta, char *origem, char *destino) {
    Aresta **arestas = grafoOriginal->arestas;
    int tamanho = grafoOriginal->tamanho;
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(arestas[i]->origem, origem) == 0) {
            if (arestas[i]->fluxoDisponivel == 0) continue;
            inserirGrafo(grafoResposta, arestas[i]);
            if (strcmp(arestas[i]->destino, destino) == 0) {
                return grafoResposta;
            } else {
                ___percorreGrafo(grafoOriginal, grafoResposta, arestas[i]->destino, destino);
            }
            if (strcmp(grafoResposta->arestas[grafoResposta->preenchido - 1]->destino, destino) == 0)
                return grafoResposta;
            removerGrafo(grafoResposta);
        }
    }
    return NULL;
}

Caminho *fordFulkerson(Grafo *grafo, char *origem, char *destino) {
    Caminho *caminhosPossiveis = criaCaminho();
    Grafo *grafoResposta = criaGrafo();
    while ((grafoResposta = ___percorreGrafo(grafo, grafoResposta, origem, destino)) != NULL) {
        ___subtrairCapacidades(grafoResposta);
        inserirCaminho(caminhosPossiveis, grafoResposta);
        grafoResposta = criaGrafo();
    }
    return caminhosPossiveis;
}

Veiculo *___buscarVeiculo(Vetor *veiculos, int fluxoGrafo) {
    Veiculo *veiculoIdeal = criaVeiculo("A", "2147483647");
    for (int i = 0; i < veiculos->preenchido; ++i) {
        if (!veiculos->registros[i]->alocado) {
            if (veiculos->registros[i]->capacidade >= fluxoGrafo &&
                veiculos->registros[i]->capacidade < veiculoIdeal->capacidade) {
                veiculoIdeal = veiculos->registros[i];
            }
        }
    }
    if (veiculoIdeal->capacidade != -1)
        veiculoIdeal->alocado = true;
    else
        veiculoIdeal = NULL;
    return veiculoIdeal;
}

void alocarVeiculos(Caminho *caminhos, Vetor *veiculos) {
    for (int i = 0; i < caminhos->preenchido; ++i) {
        caminhos->registros[i]->veiculoAlocado = ___buscarVeiculo(veiculos, caminhos->registros[i]->fluxoMaximo);
    }
}
