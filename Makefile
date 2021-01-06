FLAGS := -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS := ${patsubst %.cpp, %.o, ${wildcard *.cpp}}


c-app: ${OBJECTS}
	g++ ${OBJECTS} -o c-app ${FLAGS}

${OBJECTS}: %.o: %.cpp

clean:
	rm ${wildcard *.o}