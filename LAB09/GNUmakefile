CXX = g++
EXEC = run
CXXFLAGS = -pedantic -MMD -MP -Wall  -g -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wlogical-op -Wuseless-cast -fsanitize=address -fsanitize=leak -fsanitize=undefined

LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $(CXXFLAGS) $+ -o $@


*.o: *.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean rune rebuild

rebuild: 
	make clean
	make 

clean:
	rm -f *.o
	rm -f *~
	rm -f *.d
	rm -f $(EXEC)

rune: $(EXEC)
	./$(EXEC)

-include $(DEPS)
