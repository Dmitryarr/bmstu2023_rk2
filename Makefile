
all : test

test : main.o tasks_rk2.o
	g++ main.o tasks_rk2.o -o test

main.o : main.cpp
	g++ -c main.cpp

tasks_rk2.o : tasks_rk2.cpp
	g++ -c tasks_rk2.cpp

clean :
	rm -rf *.o test