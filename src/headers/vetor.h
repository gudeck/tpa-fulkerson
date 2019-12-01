//
// Created by guzuc on 28/11/2019.
//
#ifndef TPA_FULKERSON_VETOR_H
#define TPA_FULKERSON_VETOR_H

#include "veiculo.h"
#include "caminho.h"
#include "arquivo.h"

typedef struct ___vetor {
    int tamanho;
    int preenchido;
    Veiculo **registros;
} Vetor;

Vetor *criaVetor();

void inserirVetor(Vetor *vetor, Veiculo *novoRegistro);

void mostrarVeiculosAlocados(Vetor *veiculos);

void mostrarVeiculosNaoAlocados(Vetor *veiculos);

void mostrarVeiculosInsuficientes(Caminho *caminhos, Vetor *veiculos);

Vetor *preencherVeiculos(FILE *arquivoVeiculos);

#endif //TPA_FULKERSON_VETOR_H
