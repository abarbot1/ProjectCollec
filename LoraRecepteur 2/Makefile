all: rx

LoRa.o: LoRa.c
	gcc -c LoRa.c -o LoRa.o -lpigpio -lrt -pthread -lm

rx.o: rx.c
	gcc -c rx.c -o rx.o -lpigpio -lrt -pthread -lm
	
rx: LoRa.o rx.o
	gcc -o rx rx.o LoRa.o -lpigpio -lrt -pthread -lm

clean:
	rm *.o rx
