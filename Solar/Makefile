TARGET=render
SRCS=main.cpp render.cpp model.cpp
OBJS=$(SRCS:%.cpp=%.o)
FLAGS=-Wall -Wextra -Werror -Wfatal-errors
CCLIBS=-lglut -lGLU -lGL

all: $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS) $(CCLIBS)

.cpp.o:
	$(CC) $(FLAGS) -c -o $*.o $<

clean:
	$(RM) $(TARGET) *.o *~ core*
