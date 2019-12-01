//
// Created by guzuc on 28/11/2019.
//

#ifndef TPA_FULKERSON_VETOR_H
#define TPA_FULKERSON_VETOR_H

#include "veiculo.h"
#include "caminho.h"

typedef struct ___vetor {
    int tamanho;
    int preenchido;
    Veiculo **registros;
} Vetor;

Vetor *criaVetor();

void inserirVetor(Vetor *vetor, Veiculo *novoRegistro);

void mostrarVeiculos(Vetor *veiculos);

void mostrarNaoAlocados(Vetor *veiculos);

bool veiculosInsuficientes(Caminho *caminhos, Vetor *veiculos);

#endif //TPA_FULKERSON_VETOR_H
