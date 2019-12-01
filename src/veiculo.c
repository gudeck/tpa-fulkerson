//
// Created by guzuc on 28/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "headers/veiculo.h"
#include "headers/main.h"

Veiculo *criaVeiculo(char *placa, char *capacidade) {
    Veiculo *novoVeiculo = calloc(1, sizeof(Veiculo *));
    novoVeiculo->placa = criaString(placa);
    novoVeiculo->capacidade = strtol(capacidade, NULL, 10);
    novoVeiculo->alocado = false;
    return novoVeiculo;
}

void mostrarVeiculo(Veiculo *veiculo) {
    printf("Placa: %s, Capacidade: %d, Alocado? %d\n", veiculo->placa, veiculo->capacidade, veiculo->alocado);
}
