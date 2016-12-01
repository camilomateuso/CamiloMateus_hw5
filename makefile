data1.dat : a.out
	./a.out > data1.dat
	python grafica1.py
	rm a.out
	rm data1.dat

a.out : sismo.c
	gcc sismo.c -lm


