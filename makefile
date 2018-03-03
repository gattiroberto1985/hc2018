SHELL=/bin/sh #Shell da utilizzare per l'esecuzione dei comandi

CC=gcc #Compilatore da utilizzare

OBJECTS=hc2018.o     #File oggetto
SRCS=src/main.c    #File sorgente

#target "hc2018": generazione binario
hc2018: $(OBJECTS)
	$(CC) -o bin/$@ $<

#target "hc2018.o": generazione file oggetto
hc2018.o: $(SRCS)
	$(CC) -c -o $@ $<

#target "clean" pulisce i file oggetto e il binario nella directory corrente
clean:
	rm -f hc2018.o bin/hc2018*

#target "clean" non è un file!
.PHONY: clean
