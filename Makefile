IDIR =../include
CPP=g++
CXXFLAGS=-g -std=c++11 -I$(IDIR)

ODIR=src
LDIR =../lib

LIBS=

_DEPS = job.h offer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = offer.o scheduler.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CXXFLAGS)

scheduler: $(OBJ)
	$(CPP) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

all:
	@echo OBJ: $(OBJ)
	@echo DEPS: $(DEPS)
clean:
	rm -f $(ODIR)/*.o scheduler 
