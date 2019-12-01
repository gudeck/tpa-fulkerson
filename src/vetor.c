//
// Created by guzuc on 28/11/2019.
//

#include <stdlib.h>
#include <string.h>
#include "headers/vetor.h"

bool ___precisaExpandirVetor(Vetor *vetor) {
    return (vetor->tamanho - vetor->preenchido) == 0;
}

void ___expandeVetor(Vetor *vetor) {
    Veiculo **novoArray = calloc(vetor->tamanho + 1, sizeof(Veiculo *));
    for (int i = 0; i < vetor->preenchido; ++i) {
        novoArray[i] = vetor->registros[i];
    }
    vetor->registros = novoArray;
    vetor->tamanho = vetor->tamanho + 1;
}

bool ___veiculosInsuficientes(Caminho *caminhos, Vetor *veiculos) {
    if (caminhos->preenchido > veiculos->preenchido)
        return true;
    for (int i = 0; i < caminhos->preenchido; ++i) {
        if (caminhos->registros[i]->veiculoAlocado == NULL)
            return true;
    }
    return false;
}

Vetor *___preencherVeiculos(FILE *arquivo) {
    Vetor *novoVetor = criaVetor();
    char linha[999];
    char *placa;
    char *capacidade;
    fgets(linha, 999, arquivo);
    for (int i = 0; fgets(linha, 999, arquivo); i++) {
        placa = strtok(linha, ";");
        capacidade = strtok(NULL, "\n");
        inserirVetor(novoVetor, criaVeiculo(placa, capacidade));
    }
    return novoVetor;
}

Vetor *criaVetor() {
    int tamanho = 1;
    Vetor *novoVetor = calloc(1, sizeof(Vetor));
    novoVetor->registros = calloc(tamanho, sizeof(Veiculo *));
    novoVetor->tamanho = tamanho;
    return novoVetor;
}

void inserirVetor(Vetor *vetor, Veiculo *novoRegistro) {
    if (___precisaExpandirVetor(vetor)) ___expandeVetor(vetor);
    vetor->registros[vetor->preenchido++] = novoRegistro;
}

void mostrarVeiculosAlocados(Vetor *veiculos) {
    printf("\nOs seguintes veiculos foram alocados:\n");
    for (int i = 0; i < veiculos->preenchido; ++i) {
        if (veiculos->registros[i]->alocado)
            mostrarVeiculo(veiculos->registros[i]);
    }
    printf("\n");
}

void mostrarVeiculosNaoAlocados(Vetor *veiculos) {
    printf("\nOs seguintes veiculos nao foram alocados:\n");
    for (int i = 0; i < veiculos->preenchido; ++i) {
        if (!veiculos->registros[i]->alocado)
            mostrarVeiculo(veiculos->registros[i]);
    }
    printf("\n");
}

void mostrarVeiculosInsuficientes(Caminho *caminhos, Vetor *veiculos) {
    if (___veiculosInsuficientes(caminhos, veiculos))
        printf("\nNao ha veiculos suficientes!\n\n");
}

Vetor *preencherVeiculos(FILE *arquivoVeiculos) {
    verificaArquivo(arquivoVeiculos);
    Vetor *veiculos = ___preencherVeiculos(arquivoVeiculos);
    return veiculos;
}