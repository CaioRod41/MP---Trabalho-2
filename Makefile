all: testa_rainha

gcov: CXXFLAGS += -fprofile-arcs -ftest-coverage
gcov: LDFLAGS += -fprofile-arcs -ftest-coverage
gcov: testa_rainha
	./testa_rainha
	gcov rainha.cpp testa_rainha.cpp


testa_rainha: rainha.o testa_rainha.o
	g++ -std=c++11 -Wall $(LDFLAGS) rainha.o testa_rainha.o -o testa_rainha

rainha.o: rainha.cpp rainha.hpp
	g++ -std=c++11 -Wall $(CXXFLAGS) -c rainha.cpp


testa_rainha.o: testa_rainha.cpp rainha.hpp
	g++ -std=c++11 -Wall $(CXXFLAGS) -c testa_rainha.cpp

clean:
	rm -rf *.o testa_rainha *.gc*

compile: testa_rainha


test: testa_rainha
	./testa_rainha

cpplint: testa_rainha.cpp rainha.cpp rainha.hpp
	cpplint --exclude=catch.hpp *.*

debug: CXXFLAGS += -g
debug: LDFLAGS += -g
debug: testa_rainha
	gdb testa_rainha


cppcheck: testa_rainha.cpp rainha.cpp rainha.hpp
	cppcheck --enable=warning .


valgrind: testa_rainha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_rainha


rainha.o: rainha.cpp rainha.hpp
	g++ -std=c++11 -Wall -c rainha.cpp

testa_rainha.o: testa_rainha.cpp rainha.hpp
	g++ -std=c++11 -Wall -c testa_rainha.cpp


testa_rainha: rainha.o testa_rainha.o
	g++ -std=c++11 -Wall rainha.o testa_rainha.o -o testa_rainha
