surf_string_rho.py: string_0.00100.dat
		python surf_string_rho.py string_0.00100.dat

string_0.00100.dat: string.x
		./string.x 0.001

string.x: string.c
		cc string.c -o string.x -lm

clean:
	rm *.pdf *.dat *.x
