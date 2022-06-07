
CXX = g++
BINARY=pusher_git
build: main.o gitmanager.o decorator.o 
	@$(CXX) $^ -o $(BINARY)
clean:
	@rm *.o
	@rm $(BINARY)