TARGET=teste
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLADS=$(PTHREAD) -export-dynamic
OBJS=aula.cpp Pessoa.o DataNascimento.o
all:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)