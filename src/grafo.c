//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <string.h>
#include "headers/grafo.h"

Grafo *___preencherVertices(FILE *arquivo) {
    Grafo *novoGrafo = criaGrafo();
    char linha[999];
    char *nome;
    fgets(linha, 999, arquivo);
    nome = strtok(linha, ";");
    inserirGrafo(novoGrafo, criaAresta(nome, nome, 0, 0));
    for (int i = 1; (nome = strtok(NULL, ";")); i++) {
        inserirGrafo(novoGrafo, criaAresta(nome, nome, 0, 0));
    }
    return novoGrafo;
}

Grafo *___preencherDistancias(FILE *arquivo) {
    char linha[999];
    char *distancia;
    char *origem;
    char *destino;
    Grafo *grafoBairros = ___preencherVertices(arquivo);
    Grafo *novoGrafo = criaGrafo();
    for (int i = 0; fgets(linha, 999, arquivo); i++) {
        strtok(linha, ";");
        origem = grafoBairros->arestas[i]->origem;
        for (int j = 0; (distancia = strtok(NULL, ";")); j++) {
            if (strcmp(distancia, "0") == 0 || strcmp(distancia, "0\n") == 0) continue;
            destino = grafoBairros->arestas[j]->destino;
            inserirGrafo(novoGrafo, criaAresta(origem, destino, distancia, "0"));
        }
    }
    return novoGrafo;
}

Grafo *___preencherFluxos(FILE *arquivoDistancias, FILE *arquivoFluxos) {
    char linha[999];
    char *fluxo;
    Grafo *grafoDistancias = ___preencherDistancias(arquivoDistancias);
    fgets(linha, 999, arquivoFluxos);
    for (int i = 0, indice = 0; fgets(linha, 999, arquivoFluxos); i++) {
        strtok(linha, ";");
        for (int j = 0; (fluxo = strtok(NULL, ";")); j++) {
            if (strcmp(fluxo, "0") == 0 || strcmp(fluxo, "0\n") == 0) continue;
            grafoDistancias->arestas[indice++]->fluxoDisponivel = strtol(fluxo, NULL, 10);
        }
    }
    return grafoDistancias;
}

int ___calcularDistancia(Grafo *grafo) {
    int distanciaTotal = 0;
    for (int i = 0; i < grafo->preenchido; ++i) {
        distanciaTotal += grafo->arestas[i]->distancia;
    }
    return distanciaTotal;
}

bool ___precisaEncolherGrafo(Grafo *grafo) {
    return (grafo->tamanho - grafo->preenchido) > 0;
}

void ___encolheGrafo(Grafo *grafo) {
    Aresta **novoArray = calloc(--grafo->tamanho, sizeof(Aresta *));
    for (int i = 0; i < grafo->preenchido; ++i) {
        novoArray[i] = grafo->arestas[i];
    }
    grafo->arestas = novoArray;
}

bool ___precisaExpandirGrafo(Grafo *grafo) {
    return (grafo->tamanho - grafo->preenchido) == 0;
}

void ___expandeGrafo(Grafo *grafo) {
    Aresta **novoArray = calloc(grafo->tamanho + 1, sizeof(Aresta *));
    for (int i = 0; i < grafo->preenchido; ++i) {
        novoArray[i] = grafo->arestas[i];
    }
    grafo->arestas = novoArray;
    grafo->tamanho = grafo->tamanho + 1;
}

Grafo *criaGrafo() {
    int tamanho = 1;
    Grafo *novoVetor = calloc(1, sizeof(Grafo));
    novoVetor->arestas = calloc(tamanho, sizeof(Aresta *));
    novoVetor->tamanho = tamanho;
    return novoVetor;
}

void inserirGrafo(Grafo *grafo, Aresta *novaAresta) {
    if (___precisaExpandirGrafo(grafo)) ___expandeGrafo(grafo);
    grafo->arestas[grafo->preenchido++] = novaAresta;
}

void removerGrafo(Grafo *grafo) {
    if (___precisaEncolherGrafo(grafo))___encolheGrafo(grafo);
    grafo->arestas[grafo->preenchido--] = NULL;
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
        mostrarAresta(grafo->arestas[i]);
    }
    printf("\n");
}

void mostrarCargaPendente(Grafo *grafo) {
    printf("\nCentros com carga pendente:\n");
    for (int i = 0; i < grafo->preenchido; ++i) {
        if (grafo->arestas[i]->fluxoDisponivel > 0)
            mostrarAresta(grafo->arestas[i]);
    }
    printf("\n");
}

Grafo *preencherGrafo(FILE *arquivoDistancias, FILE *arquivoFluxos) {
    verificaArquivo(arquivoDistancias);
    verificaArquivo(arquivoFluxos);
    return ___preencherFluxos(arquivoDistancias, arquivoFluxos);
}
