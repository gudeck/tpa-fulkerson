//
// Created by guzuc on 09/11/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include "headers/aresta.h"
#include "headers/main.h"

Aresta *criaAresta(char *origem, char *destino, char *distancia, char *fluxoDisponivel) {
    Aresta *novaAresta = calloc(1, sizeof(Aresta));
    novaAresta->origem = criaString(origem);
    novaAresta->destino = criaString(destino);
    novaAresta->distancia = strtol(distancia, NULL, 10);
    novaAresta->fluxoDisponivel = strtol(fluxoDisponivel, NULL, 10);
    return novaAresta;
}

void mostrarAresta(Aresta *aresta) {
    printf("%s -> %s, Distancia: %d, Fluxo Disponivel: %d\n",
           aresta->origem, aresta->destino,
           aresta->distancia, aresta->fluxoDisponivel);
}
