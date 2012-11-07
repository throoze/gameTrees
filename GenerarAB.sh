
# Shell script para ejecutar los algotirmos sobre
# Arboles de Juego MinMax,A-B_Pruning y NegaScout
# sobre la variante principal

# Las profundidas a ser probadas.
nums="33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"

# El numero de Gigas de ram
ulimit -v 5767168

#El tiempo en Segundos => 40 min
time='2400'
ulimit -t $time

echo "Llamando A-B_Prunning"
for case in $nums
do
    echo "Profundidad: ${case}"
    ./othello AB ${case} >> AB_Pruning 2>&1
done
