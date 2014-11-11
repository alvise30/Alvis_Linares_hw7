graficando.py: estado_0.1.dat
		python graficando.py estado_0.1.dat

estado_0.1.dat: sod_test.x
		./sod_test.x 0.1

sod_test.x: shock.c
		cc shock.c -o sod_test.x -lm

clean:
	rm *.pdf *.dat *.x
