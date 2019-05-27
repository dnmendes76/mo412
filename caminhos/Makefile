CC=g++
IDIR=./sources/inc
ODIR=./sources/obj
VPATH=./sources/src

# nome do executavel
TARGET=main

#adicionar os .h's
_DEPS = graph.h heap_binary.h caminho_minimo.h bellman_ford.h djikstra.h johnson.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# adicionar o nome dos .o's
_OBJ = graph.o main.o heap_binary.o bellman_ford.o djikstra.o johnson.o
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
