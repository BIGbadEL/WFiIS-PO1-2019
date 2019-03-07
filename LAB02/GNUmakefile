CXX = g++
EXEC = main.exe
CXXFLAGS = -pedantic -MMD -MP -Wall  -g  #-fsanitize=address -fsanitize=leak -fsanitize=undefined

LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $(CXXFLAGS) $+ -o $@


*.o: *.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run rebuild

rebuild: 
	make clean
	make run

clean:
	rm -f *.o
	rm -f *~
	rm -f *.d
	rm -f $(EXEC)

run: $(EXEC)
	./$(EXEC)

-include $(DEPS)
