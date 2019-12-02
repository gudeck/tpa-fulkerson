//
// Created by guzuc on 28/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "headers/veiculo.h"
#include "headers/main.h"

Veiculo *criaVeiculo(char *placa, char *nomeMotorista, char *capacidade) {
    Veiculo *novoVeiculo = calloc(1, sizeof(Veiculo *));
    novoVeiculo->placa = criaString(placa);
    novoVeiculo->nomeMotorista = criaString(nomeMotorista);
    novoVeiculo->capacidade = strtol(capacidade, NULL, 10);
    novoVeiculo->alocado = false;
    return novoVeiculo;
}

void mostrarVeiculo(Veiculo *veiculo) {
    printf("Placa: %s, Motorista: %s, Capacidade: %d\n", veiculo->placa,
           veiculo->nomeMotorista, veiculo->capacidade);
}
