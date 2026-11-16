# Graficas de la integral de BK 1D en r = r_s = 1/Q_s0 (GBW)

set term pdfcairo enhanced font "Helvetica,11" size 6in,4in
set grid
set key right bottom box opaque
set ylabel "I(r_{min}, r_{max})"

# RMAX FIXED
set output "I_vs_rmin.pdf"
set title "Integral de BK 1D vs r_{min}  (r_{max} fijo, r = r_s)"
set xlabel "r_{min} [GeV^{-1}]"
set key left top
p "integral.txt" index 0 u 2:3 w l lw 2 t "r_{max} = 5 r_s", \
  ""             index 1 u 2:3 w l lw 2 t "r_{max} = 10 r_s", \
  ""             index 2 u 2:3 w l lw 2 t "r_{max} = 20 r_s"
set output

# RMIN FIXED
set output "I_vs_rmax.pdf"
set title "Integral de BK 1D vs r_{max}  (r_{min} fijo, r = r_s)"
set xlabel "r_{max} [GeV^{-1}]"
set key right bottom
p "integral.txt" index 3 u 2:3 w l lw 2 t "r_{min} = 0.01 r_s", \
  ""             index 4 u 2:3 w l lw 2 t "r_{min} = 0.1 r_s", \
  ""             index 5 u 2:3 w l lw 2 t "r_{min} = 0.5 r_s"
set output
