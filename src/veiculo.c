//
// Created by guzuc on 28/11/2019.
//

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
