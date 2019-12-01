//
// Created by guzuc on 28/11/2019.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "headers/vetor.h"

Vetor *criaVetor() {
    int tamanho = 1;
    Vetor *novoVetor = calloc(1, sizeof(Vetor));
    novoVetor->registros = calloc(tamanho, sizeof(Veiculo *));
    novoVetor->tamanho = tamanho;
    return novoVetor;
}

bool precisaExpandirVetor(Vetor *vetor) {
    return (vetor->tamanho - vetor->preenchido) == 0;
}

void expandeVetor(Vetor *vetor) {
    Veiculo **novoArray = calloc(vetor->tamanho + 1, sizeof(Veiculo *));
    for (int i = 0; i < vetor->preenchido; ++i) {
        novoArray[i] = vetor->registros[i];
    }
    vetor->registros = novoArray;
    vetor->tamanho = vetor->tamanho + 1;
}

void inserirVetor(Vetor *vetor, Veiculo *novoRegistro) {
    if (precisaExpandirVetor(vetor)) expandeVetor(vetor);
    vetor->registros[vetor->preenchido++] = novoRegistro;
}

void mostrarVeiculos(Vetor *veiculos) {
    for (int i = 0; i < veiculos->preenchido; ++i) {
        printf("P:%s C:%d A:%d\n", veiculos->registros[i]->placa, veiculos->registros[i]->capacidade,
               veiculos->registros[i]->alocado);
    }
}