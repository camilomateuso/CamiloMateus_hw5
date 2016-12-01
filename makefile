onda.dat : a.out
	./a.out > data1.dat
	python grafica.py
	rm a.out
	rm data1.dat

a.out : gravedad.c
	gcc gravedad.c -lm


