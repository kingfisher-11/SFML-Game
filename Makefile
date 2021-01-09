FLAGS := -lsfml-graphics -lsfml-window -lsfml-system
HEADERS := ${wildcard *.hpp}
OBJECTS := ${patsubst %.hpp, %.o, ${HEADERS}}


c-app: ${OBJECTS} main.o
	g++ main.o ${OBJECTS} -o c-app ${FLAGS}

main.o: main.cpp ${OBJECTS}

${OBJECTS}: %.o: %.cpp %.hpp

clean:
	rm ${wildcard *.o}; rm c-app
