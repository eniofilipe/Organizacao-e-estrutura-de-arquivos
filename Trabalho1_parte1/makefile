TARGET=teste
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLADS=$(PTHREAD) -export-dynamic
OBJS=parte1.cpp Venda.o DataVenda.o
all:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)