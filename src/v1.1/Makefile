# # Coms:   Makefile baisco
# #------------------------------------------------------------------------------

# #---------------------------------------------------------
# # Definición de macros
# CC = g++
# CPPFLAGS = -g -std=c++11      #opciones de compilación
# LDFLAGS =                      #opciones de linkado
# RM = rm -f                     #comando para borrar ficheros

# all:  clean main 
# #-----------------------------------------------------------
# # Compilacion
# #g++ -std=c++11  main.cpp -o main
# main.o: main.cc 
# 	${CC} -c main.cc  ${CPPFLAGS}


# # Linkado
# main: main.o  
# 	${CC} main.o  -o main ${LDFLAGS}
	


# #-----------------------------------------------------------	
# clean:
# 	${RM} main.o 
# 	${RM} main
	
PROG:=main
SRCS:=main.cc userConcreteObserver.cc  feedConcreteSubject.cc feedSubject.cc observer.cc 

CXX:=g++ -std=c++20 -Wall -Wfatal-errors 

OBJS:=$(SRCS:.cc=.o)
DEPS:=$(SRCS:.cc=.d)

all: main

main: $(OBJS)
	$(CXX) -MMD -o $@ $^

%.o: %.cc
	$(CXX) -MMD -c $<

.PHONY: edit

edit:
	@geany -s -i $(SRCS) *.h &

clean:
	@rm -f $(PROG) *.o *.d core

-include $(DEPS)