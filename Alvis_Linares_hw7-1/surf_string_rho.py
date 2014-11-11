from pylab import *
import matplotlib.pyplot as plt
import sys
from mpl_toolkits.mplot3d import Axes3D

nombre = sys.argv[1];
datos = loadtxt(nombre)
fig = figure()
ax = fig.add_subplot(111, projection='3d')
x = linspace(0,101,101)
y = linspace(0, 121, 121)

arr = nombre.split("_")
arr1 = arr[1].split(".dat")
rho = arr1[0]

for i in range(len(datos)):
    x = linspace(0,101, len(datos[i]))
    y = datos[i]
    z = [ i for j in range(len(datos[i]))]

plot(x,z,y, color='r' )
ax.set_xlabel("eje X")
ax.set_ylabel("Tiempo(s)")
ax.set_zlabel("Altura")
title("Movimiento de la Cuerda")
savefig("cuerda_"+rho+".pdf")
close()

