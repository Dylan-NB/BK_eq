set term pdfcairo enhanced font "Helvetica,11" size 6in,4in
set grid
set logscale x
set format x "10^{%L}"
set ylabel "I(r_{min}, r_{max})"

# RMAX FIXED
set output "I_vs_rmin_log.pdf"
set title "Integral de BK 1D vs r_{min}  (r_{max} fijo, grilla en ln r')"
set xlabel "r_{min} [GeV^{-1}]"
set key left top box opaque
p "integral_log.txt" index 0 u 2:3 w l lw 2 t "r_{max} = 5 r_s", \
  ""                 index 1 u 2:3 w l lw 2 t "r_{max} = 10 r_s", \
  ""                 index 2 u 2:3 w l lw 2 t "r_{max} = 20 r_s"
set output

# RMIN FIXED
set output "I_vs_rmax_log.pdf"
set title "Integral de BK 1D vs r_{max}  (r_{min} fijo, grilla en ln r')"
set xlabel "r_{max} [GeV^{-1}]"
set key right bottom box opaque
p "integral_log.txt" index 3 u 2:3 w l lw 2 t "r_{min} = 10^{-4} r_s", \
  ""                 index 4 u 2:3 w l lw 2 t "r_{min} = 0.01 r_s", \
  ""                 index 5 u 2:3 w l lw 2 t "r_{min} = 0.1 r_s"
set output
