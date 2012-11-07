Universidad Simón Bolívar
Inteligencia Artificial I
Profesor: Blai Bonet

Integrantes:
Victor De Ponte   05-38087
Jesus Torres      06-40386
Tony Lattke       07-41092

Sartenejas 6 de noviembre de 2012

======================================Programación=======================================

El lenguaje de programación que se uso para implementar las distintas soluciones fue c++
debido a la necesidad de optimizar el código en tiempo y en espacio.

Se implementaron los algoritmos de arboles de juego Minmax, Alphabeta-Pruning y Negascout

////////////////////////////////////////////Uso///////////////////////////////////////////

- Compilar

    Para generar el programa debes acceder situarte en la carpeta del proyecto ejecutar el
    comando make, esto compilara los archivos necesarios para trabajar.

- Sintaxis

    ./othello <MM|AB|NS> <Caso>

    MM : correr algoritmo MinMax
    AB : correr algoritmo Alphabeta-Pruning
    NS : correr algoritmo NegaScout
    Caso : Profundidad en el arbol. A mayor profundidad estas mas cerca del estado del
    juego final

- Casos de MinMax script

    Para correr este algoritmo solo tenemos que correr el script de prueba GenerarMM.sh con
    el comando sh GenerarMM.sh y este ira imprimiendo en pantalla la profundidad actual
    que esta corriendo el algoritmo. Al pasar 40 minutos vera un archivo generado en el
    mismo directorio con el nombre MinMax el cual tendra todos los resultados obtenidos
    en cada nivel del arbol.

- Casos de Alphabeta-Pruning script

    Para correr este algoritmo solo tenemos que correr el script de prueba GenerarAB.sh con
    el comando sh GenerarAB.sh y este ira imprimiendo en pantalla la profundidad actual
    que esta corriendo el algoritmo. Al pasar 40 minutos vera un archivo generado en el
    mismo directorio con el nombre AB_Pruning el cual tendra todos los resultados obtenidos
    en cada nivel del arbol.

- Casos de NegaScout script

    Para correr este algoritmo solo tenemos que correr el script de prueba GenerarNS.sh con
    el comando sh GenerarNS.sh y este ira imprimiendo en pantalla la profundidad actual
    que esta corriendo el algoritmo. Al pasar 40 minutos vera un archivo generado en el
    mismo directorio con el nombre NegaScout el cual tendra todos los resultados obtenidos
    en cada nivel del arbol.
