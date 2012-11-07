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

#include <stdlib.h>
#include <list>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#ifndef OTHELLO
#define OTHELLO
#include "othello_cut.h"
#endif

#include "arbolesJuego.h"

using namespace std;

int main(int argc, const char **argv) {

    if(!argc == 3)
    {
        cout << "Error en los parametros." << endl;
        cout << "Sintaxis Correcta ./othello <MM|AB|NS> <Caso>" << endl;
        return 1;
    }

    struct timeval t;
    double inicio =0.0;
    double final  =0.0;
    int vj; //Valor del Juego;

    int caso = atoi(argv[2]);
    bool color = false; //Black or White

    state_t Nodo = Nodo.genInit(caso, color); //Caso a Calcular

    gettimeofday(&t,NULL);
    inicio = (double) t.tv_sec + ((double) t.tv_usec)/1000000.0;

    if(!strcmp(argv[1],"MM")) //Min_Max
        vj = arbolesJuego::minimax_run(Nodo , color);
    if(!strcmp(argv[1],"AB")) //A-B_Prunig
        vj = arbolesJuego::alphabeta_run(Nodo , color);
    if(!strcmp(argv[1],"NS")) //NegaScout
         vj = arbolesJuego::negascout_run(Nodo ,color);

    gettimeofday(&t,NULL);
    final = (double) t.tv_sec + ((double) t.tv_usec)/1000000.0;

    //Profundidad en el arbol \|caso valor del juego \| Nodos expandidos \| tiempo
    cout << caso << " | " <<  vj << " | " << arbolesJuego::retNod() << " | " << final-inicio << endl;

    return 0;
}
