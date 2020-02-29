TARGET=teste
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLADS=$(PTHREAD) -export-dynamic
OBJS=leitura.cpp Pessoa.o
all:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)