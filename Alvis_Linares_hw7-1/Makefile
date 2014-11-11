surf_string_rho.py: string_rho.dat
		surf_string_rho.py

string_rho.dat: string.x
		./string.x 0.001

string.x: string.c
		cc string.c -o string.x -lm

clean:
	rm *.pdf *.dat *.x
