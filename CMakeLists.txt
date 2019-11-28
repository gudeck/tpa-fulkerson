cmake_minimum_required(VERSION 3.14)
project(tpa_fulkerson C)

set(CMAKE_C_STANDARD 11)

add_executable(tpa_fulkerson
        src/headers/aresta.h
        src/headers/arquivo.h
        src/headers/main.h
        src/headers/grafo.h
        src/aresta.c
        src/arquivo.c
        src/main.c
        src/grafo.c src/veiculo.c src/headers/veiculo.h src/vetor.c src/headers/vetor.h src/fulkerson.c src/headers/fulkerson.h src/caminho.c src/headers/caminho.h)