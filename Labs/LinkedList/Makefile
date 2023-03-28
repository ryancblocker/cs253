CXX=g++

CXXFLAGS=-std=c++17 -Wall # -Wextra -Wpedantic -Werror -Wfatal-errors


link: main.o ll.o
	$(CXX) $(CXXFLAGS) main.o ll.o -o link

main.o: main.cc ll.h
	$(CXX) $(CXXFLAGS) -c main.cc

ll.o: ll.cc ll.h
	$(CXX) $(CXXFLAGS) -c ll.cc

clean:
	-rm -f link *.o
