set term pdfcairo enhanced font "Helvetica,11" size 6in,4in
set output "plots/evolucion.pdf"

set title "Evolución de BK 1D (RK4, {/Symbol a}_s = 0.2, GBW)"
set xlabel "r [GeV^{-1}]"
set ylabel "N(y, r)"
set logscale x
set format x "10^{%L}"
set xrange [1e-3:1e2]
set yrange [0:1.05]
set grid
set key left top box opaque

p "plots/evolucion.txt" index 0 u 2:3 w l lw 2 t "y = 0", \
  ""                   index 1 u 2:3 w l lw 2 t "y = 1", \
  ""                   index 2 u 2:3 w l lw 2 t "y = 5", \
  ""                   index 3 u 2:3 w l lw 2 t "y = 10"

set output
