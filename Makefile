FLAGS := -lsfml-graphics -lsfml-window -lsfml-system
HEADERS := ${wildcard *.hpp}
OBJECTS := ${patsubst %.hpp, %.o, ${HEADERS}}


c-app: ${OBJECTS} main.o
	g++ main.o ${OBJECTS} -o c-app ${FLAGS}

${OBJECTS}: %.o: %.cpp %.hpp

main.o: main.cpp

clean:
	rm ${wildcard *.o}