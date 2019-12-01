//
// Created by guzuc on 28/11/2019.
//

#ifndef TPA_FULKERSON_VEICULO_H
#define TPA_FULKERSON_VEICULO_H

#include <stdbool.h>

typedef struct ___veiculo {
    char *placa;
    int capacidade;
    bool alocado;
} Veiculo;

Veiculo *criaVeiculo(char *placa, char *capacidade);

#endif //TPA_FULKERSON_VEICULO_H
