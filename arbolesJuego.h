/*
 * Universidad Simón Bolívar
 * Inteligencia Artificial I
 * Profesor: Blai Bonet

 * Integrantes:
 * Victor De Ponte   05-38087
 * Jesus Torres      06-40386
 * Tony Lattke       07-41092

 * Sartenejas 6 de noviembre de 2012
 */
#include "hashTable.h"
#ifndef ARBOLESJUEGO_H
#define ARBOLESJUEGO_H
#include <iostream>
#include <sstream>
#include <limits.h>
#include <vector>

#include "hashTable.h"

#ifndef OTHELLO
#define OTHELLO
#include "othello_cut.h"
#endif

using namespace std;

class arbolesJuego{
    public:
        //Atributos

        //Funciones
        static unsigned long long int retNod();
        static int print(state_t n, bool color, int depth); //Imprime el Grafo

        static int minimax_run(state_t n, bool color);
        static int alphabeta_run(state_t n, bool color);
        static int negascout_run(state_t,bool Color);



    private: //Funciones para llamadas recursivas
        static int ValorMax(state_t n);
        static int ValorMin(state_t n);

        static int ValorMax(state_t n, int alpha, int beta);
        static int ValorMin(state_t n, int alpha, int beta);

        static int MaxScout(state_t n, int alpha, int beta);
        static int MinScout(state_t n, int alpha, int beta);
};

#endif
