CC=g++
IDIR=./sources/inc
ODIR=./sources/obj
VPATH=./sources/src

# nome do executavel
TARGET=main

#adicionar os .h's
_DEPS = grafo.h kruskal.h union_find.h heap_binary.h soluction.h prim.h heap_fibonacci.h heap_vector.h filter_kruskal.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# adicionar o nome dos .o's
_OBJ = grafo.o main.o kruskal.o union_find.o heap_binary.o prim.o heap_fibonacci.o heap_vector.o filter_kruskal.o
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
