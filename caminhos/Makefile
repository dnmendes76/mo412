CC=g++
IDIR=./sources/inc
ODIR=./sources/obj
VPATH=./sources/src

# nome do executavel
TARGET=main

#adicionar os .h's
_DEPS = graph.h heap_binary.h heap_fibonacci.h caminho_minimo.h bellman_ford.h dijkstra.h johnson.h floyd_warshall.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# adicionar o nome dos .o's
_OBJ = graph.o main.o heap_binary.o heap_fibonacci.o bellman_ford.o dijkstra.o johnson.o floyd_warshall.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CFLAGS=-std=c++11 -DIL_STD -O -DNDEBUG -I$(IDIR) -I$(CPLEXDIR)/include	\
-I$(CONCERTDIR)/include -fstrict-aliasing -pedantic -g -Wall		\
-fexceptions -ffloat-store -DILOUSEMT -D_REENTRANT -DILM_REENTRANT

.PHONY: all clean

all: $(TARGET)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ $(TARGET)
