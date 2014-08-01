all: i386encoder
	rm main.o i386encode.o

i386encode.o: i386encode.cpp
	g++ -c i386encode.cpp -o i386encode.o

main.o: main.cpp i386encode.o
	g++ -c main.cpp i386encode.o -o main.o

i386encoder: main.o i386encode.o
	g++ main.o i386encode.o -o i386encoder

run:
	./i386encoder

clean:
	rm i386encoder
	rm -f *.o
