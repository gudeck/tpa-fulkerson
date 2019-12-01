cmake_minimum_required(VERSION 3.14)
project(tpa_fulkerson C)
set(CMAKE_C_STANDARD 11)
add_executable(tpa_fulkerson
        src/headers/aresta.h
        src/headers/arquivo.h
        src/headers/caminho.h
        src/headers/fulkerson.h
        src/headers/grafo.h
        src/headers/main.h
        src/headers/veiculo.h
        src/headers/vetor.h
        src/aresta.c
        src/arquivo.c
        src/caminho.c
        src/fulkerson.c
        src/grafo.c
        src/main.c
        src/veiculo.c
        src/vetor.c)