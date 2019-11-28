//
// Created by guzuc on 28/11/2019.
//

#include <stdlib.h>
#include "headers/veiculo.h"
#include "headers/main.h"

Veiculo *criaVeiculo(char *placa, char *capacidade) {
    Veiculo *novoVeiculo = calloc(1, sizeof(Veiculo *));
    novoVeiculo->capacidade = strtod(capacidade, NULL);
    novoVeiculo->placa = criaString(placa);
    return novoVeiculo;
}
