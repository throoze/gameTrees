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


#include "arbolesJuego.h"
static unsigned long long int Nnodes;
hash_table_t trans;

/* Devuelve el numero de nodos expandidos
 * return: el numero de nodos expandidos
 */
unsigned long long int arbolesJuego::retNod(){
    return Nnodes;
}

/* Imprime el arbol de juego
 */
int arbolesJuego::print(state_t n, bool color, int depth){
    for(int i=0;i<depth;++i)
        cout << "    ";

    if(color)
        cout << "MAX";
    else
        cout << "MIN";

    if(n.terminal()){
        cout << n.value() <<endl;
        return 0;
    }

    list<state_t > sucesores = n.succe(color);

    cout << " ( " << sucesores.size()  << " ) "<< endl;

    if (sucesores.size() == 0)
        print(n,!color,depth+1);

    state_t aux;
    while (sucesores.size() > 0) {
        aux = sucesores.front();
        sucesores.pop_front();
        print(aux,!color,depth+1);
    }
    return 0;
}

/* Ejecuta el algoritmo MinMax para el estado de juego n con el player color y devuelve el
 * valor del estado de juego
 * return: el valor del estado de juego
 */
int arbolesJuego::minimax_run(state_t n, bool color){
    Nnodes = 0;
    int res;
    if(color) {
    res = ValorMax(n);
    } else {
      res = ValorMin(n);
    }

    return res;

}

/* Ejecuta el algoritmo Max en el estado n siendo player MAX
 * return: el valor del estado de juego
 */
int arbolesJuego::ValorMax(state_t n){
    ++Nnodes;
    if(n.terminal()){
        return n.value();
    }

    int alpha = INT_MIN;
    list<int> sucesores = n.succ(true);
    int aux;

    if (sucesores.size() == 0) {
        alpha = ValorMin(n);
        hash_table_t::iterator it = trans.find(n);
        if ( it == trans.end() ) {
          stored_info_t info;
          info_t b;
          b.value = alpha;
          info.black = b;
          trans.insert(make_pair(n,info));
        } else {
          stored_info_t siaux = trans[n];
          siaux.black.value = MAX(siaux.black.value, alpha);
          trans[n] = siaux;
        }
    }

    while (sucesores.size() > 0) {
        aux = sucesores.front();
        sucesores.pop_front();
        state_t newst = n.move(true,aux);
        hash_table_t::iterator it = trans.find(newst);
        if ( it == trans.end() ) {
          int tmp = ValorMin(newst);
          alpha = MAX(alpha, tmp);
          stored_info_t info;
          info_t b;
          b.value = alpha;
          info.black = b;
          trans.insert(make_pair(newst,info));
          return alpha;
        } else {
          stored_info_t siaux = trans[newst];
          int vaux = siaux.black.value;
          siaux.black.value = MAX(vaux, alpha);
          trans[newst] = siaux;
          return siaux.black.value;
        }
    }
    return alpha;
}

/* Ejecuta el algoritmo Min en el estado n siendo player MIN
 * return: el valor del estado de juego
 */
int arbolesJuego::ValorMin(state_t n){
    ++Nnodes;
    if(n.terminal()){
        return n.value();
    }

    int beta = INT_MAX;
    list<int> sucesores = n.succ(false);
    int aux;

    if (sucesores.size() == 0) {
          beta = ValorMax(n);
        hash_table_t::iterator it = trans.find(n);
        if ( it == trans.end() ) {
          stored_info_t info;
          info_t w;
          w.value = beta;
          info.white = w;
          trans.insert(make_pair(n,info));
        } else {
          stored_info_t siaux = trans[n];
          siaux.white.value = MIN(siaux.white.value, beta);
          trans[n] = siaux;
        }
    }

    while (sucesores.size() > 0) {
      aux = sucesores.front();
      sucesores.pop_front();
      state_t newst = n.move(false,aux);
      hash_table_t::iterator it = trans.find(newst);
      if ( it == trans.end() ) {
        int tmp = ValorMax(newst);
        beta = MIN(beta, tmp);
        stored_info_t info;
        info_t w;
        w.value = beta;
        info.white = w;
        trans.insert(make_pair(newst,info));
        return beta;
      } else {
        stored_info_t siaux = trans[newst];
        int vaux = siaux.white.value;
        siaux.white.value = MIN(vaux, beta);
        trans[newst] = siaux;
        return siaux.white.value;
      }
    }
    return beta;
}

/* Ejecuta el algoritmo Alphabeta Pruning para el estado de juego n con el player color y
 * devuelve el valor del estado de juego
 * return: el valor del estado de juego
 */
int arbolesJuego::alphabeta_run(state_t n, bool color){
    Nnodes = 0;
    int res;
    if(color)
        res = ValorMax(n,INT_MIN,INT_MAX);
    else
        res = ValorMin(n,INT_MIN,INT_MAX);

    return res;
}

/* Ejecuta el algoritmo Max en el estado n siendo player MAX, con alpha y beta
 * return: el valor del estado de juego
 */
int arbolesJuego::ValorMax(state_t n, int alpha, int beta){
    ++Nnodes;
    if(n.terminal()){
        return n.value();
    }

    list<int> sucesores = n.succ(true);
    int aux;

    if (sucesores.size() == 0)
        alpha = MAX(alpha, ValorMin(n, alpha, beta));

    while (sucesores.size() > 0) {
        aux = sucesores.front();
        sucesores.pop_front();
        int tmp = ValorMin(n.move(true,aux), alpha, beta);
        alpha = MAX(alpha, tmp);

        if (alpha >= beta){
            return beta;
        }
    }
    return alpha;
}

/* Ejecuta el algoritmo Min en el estado n siendo player MIN, con alpha y beta
 * return: el valor del estado de juego
 */
int arbolesJuego::ValorMin(state_t n, int alpha, int beta){
    ++Nnodes;
    if(n.terminal()){
        return n.value();
    }

    list<int> sucesores = n.succ(false);
    int aux;

    if (sucesores.size() == 0)
        beta = MIN(beta, ValorMax(n, alpha, beta));

    while (sucesores.size() > 0) {
        aux = sucesores.front();
        sucesores.pop_front();
        int tmp = ValorMax(n.move(false,aux), alpha, beta);
        beta = MIN(beta, tmp);

        if (alpha >= beta){
            return alpha;
        }
    }
    return beta;
}

/* Ejecuta el algoritmo NegaScout para el estado de juego n con el player color y devuelve
 * el valor del estado de juego
 * return: el valor del estado de juego
 */
int arbolesJuego::negascout_run(state_t n, bool color){
    Nnodes = 0;
    int res;
    if(color)
        res = MaxScout(n,INT_MIN,INT_MAX);
    else
        res = MinScout(n,INT_MIN,INT_MAX);

    return res;

}

/* Ejecuta el algoritmo Max para NegaScout en el estado n siendo player MAX, con alpha y beta
 * return: el valor del estado de juego
 */
int arbolesJuego::MaxScout(state_t n, int alpha, int beta){
    ++Nnodes;
    if(n.terminal())
        return n.value();

    list<int> sucesores = n.succ(true);

    int m,t;

    if (sucesores.size() == 0)
        m = MinScout(n,alpha,beta);

    int aux;
    bool pH = true;
    while (sucesores.size() > 0) {
        aux = sucesores.front();
        sucesores.pop_front();
        if(pH){
            m = INT_MIN;
            m = MAX(m,MinScout(n.move(true,aux),alpha,beta));
            if(m >= beta)
                return m;
        }else{
            t = MinScout(n.move(true,aux),m,m+1);
            if(t>m)
                if(t >= beta)
                    m = t;
                else
                    m = MinScout(n.move(true,aux),t,beta);

            if(m >= beta)
                return m;
        }
        pH = false;
    }
    return m;
}

/* Ejecuta el algoritmo Min para NegaScout en el estado n siendo player MIN, con alpha y beta
 * return: el valor del estado de juego
 */
int arbolesJuego::MinScout(state_t n, int alpha, int beta){
    ++Nnodes;
    if(n.terminal())
        return n.value();

    list<int> sucesores = n.succ(false);

    int m,t;

    if (sucesores.size() == 0)
        m = MaxScout(n,alpha,beta);

    int aux;
    bool pH = true;
    while (sucesores.size() > 0) {
        aux = sucesores.front();
        sucesores.pop_front();
        if(pH){
            m = INT_MAX;
            m = MIN(m,MaxScout(n.move(false,aux),alpha,beta));
            if(m <= alpha)
                return m;
        }else{
            t = MaxScout(n.move(false,aux),m,m+1);
            if(t<=m)
                if(t <= alpha)
                    m = t;
                else
                    m = MaxScout(n.move(false,aux),alpha,t);

            if(m <= alpha)
                return m;
        }
        pH = false;
    }
    return m;
}
