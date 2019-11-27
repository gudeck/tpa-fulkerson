//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <string.h>
#include "headers/arquivo.h"
#include "headers/grafo.h"

void verificaArquivo(FILE *arquivo) {
    if (!arquivo) {
        printf("\nFalha ao abrir o arquivo!\n");
        exit(0);
    }
}

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
            grafoDistancias->arestas[indice++]->fluxoDisponivel = strtod(fluxo, NULL);
        }
    }
    return grafoDistancias;
}

Grafo *preencherGrafo(FILE *arquivoDistancias, FILE *arquivoFluxos) {
    verificaArquivo(arquivoDistancias);
    verificaArquivo(arquivoFluxos);
    return ___preencherFluxos(arquivoDistancias, arquivoFluxos);
}
