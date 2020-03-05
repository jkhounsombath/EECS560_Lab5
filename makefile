Lab5: main.o Executive.o hashTableQuadratic.o User.o hashTableDouble.o
	g++ -g -std=c++11 -Wall main.o Executive.o hashTableQuadratic.o hashTableDouble.o -o Lab5

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.cpp hashTableDouble.h hashTableQuadratic.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

hashTableDouble.o: hashTableDouble.cpp
	g++ -g -std=c++11 -Wall -c hashToubleDouble.cpp

hashTableQuadratic.o: hashTableQuadratic.cpp
	g++ -g -std=c++11 -Wall -c hashTableQuadratic.cpp

clean:
	rm *.o Lab5
