SRCS1 = dijkstra.cpp 
SRCS2 = prims.cpp

EXE1 = dijkstra 
EXE2 = prims

CXX=g++
LD=g++
CC=g++

OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)

CXXFLAGS = -g  -std=c++17 -O3

.SUFFIXES: .cpp

.cpp.o:  
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: 
	make dijkstra
	make prims
	
dijkstra:$(OBJS1)
	$(CXX) -o $(EXE1) $(OBJS1)

prims:$(OBJS2)
	$(CXX) -o $(EXE2) $(OBJS2)

test:
	./dijkstra
	./prims

clean:
	-rm $(OBJS1)
	-rm $(EXE1)
	-rm $(OBJS2)
	-rm $(EXE2)