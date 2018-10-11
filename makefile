CC = g++
OBJS = JsonBagIdea.o
source = main.cpp

all: $(OBJS)
	$(CC) $(source) $(OBJS) -o out

JsonBagIdea.o:
	$(CC) -c JsonBagIdea.cpp 

run:
	./out

clean:
	rm -rf out JsonBagIdea.o
