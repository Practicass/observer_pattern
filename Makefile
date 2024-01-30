# Coms:   Makefile baisco
#------------------------------------------------------------------------------

#---------------------------------------------------------
# Definición de macros
CC = g++
CPPFLAGS = -g -std=c++11      #opciones de compilación
LDFLAGS =                      #opciones de linkado
RM = rm -f                     #comando para borrar ficheros

all:  clean main 
#-----------------------------------------------------------
# Compilacion
#g++ -std=c++11  main.cpp -o main
main.o: main.cpp  
	${CC} -c main.cpp  ${CPPFLAGS}


# Linkado
main: main.o  
	${CC} main.o  -o main ${LDFLAGS}
	


#-----------------------------------------------------------	
clean:
	${RM} main.o 
	${RM} main
	
