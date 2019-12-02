//
// Created by guzuc on 28/11/2019.
//
#ifndef TPA_FULKERSON_VEICULO_H
#define TPA_FULKERSON_VEICULO_H

#include <stdbool.h>

typedef struct ___veiculo {
    char *placa;
    char *nomeMotorista;
    int capacidade;
    bool alocado;
} Veiculo;

Veiculo *criaVeiculo(char *placa, char *nomeMotorista, char *capacidade);

void mostrarVeiculo(Veiculo *veiculo);

#endif //TPA_FULKERSON_VEICULO_H
