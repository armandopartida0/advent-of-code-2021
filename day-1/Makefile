CC      = g++
C       = cpp

CFLAGS  = -g

PROJECT		= main

OBJECTS = ${PROJECT}.o

${PROJECT}:	${PROJECT}.o
	${CC} ${CFLAGS} ${LFLAGS} -o ${PROJECT} ${OBJECTS} ${LDFLAGS}

%.o: %.cpp
	${CC} -c ${CFLAGS} *.${C}

clean:
	rm -f core.* *.o *~ ${PROJECT}