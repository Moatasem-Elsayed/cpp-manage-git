
CXX = g++
BUILD_DIRECTORY=build/
$(BUILD_DIRECTORY)pusher_git: $(BUILD_DIRECTORY)main.o $(BUILD_DIRECTORY)gitmanager.o $(BUILD_DIRECTORY)decorator.o
	@$(CXX) $(BUILD_DIRECTORY)main.o $(BUILD_DIRECTORY)gitmanager.o $(BUILD_DIRECTORY)decorator.o -o $(BUILD_DIRECTORY)pusher_git
$(BUILD_DIRECTORY)main.o: main.cpp $(BUILD_DIRECTORY)
	@$(CXX) --std=c++17 -c main.cpp -o $(BUILD_DIRECTORY)main.o
$(BUILD_DIRECTORY)gitmanager.o: gitmanager.cpp $(BUILD_DIRECTORY)
	@$(CXX) --std=c++17 -c gitmanager.cpp -o $(BUILD_DIRECTORY)gitmanager.o
$(BUILD_DIRECTORY)decorator.o: decorator.cpp $(BUILD_DIRECTORY)
	@$(CXX) --std=c++17 -c decorator.cpp -o $(BUILD_DIRECTORY)decorator.o
$(BUILD_DIRECTORY):
	@mkdir build
clean:
	@rm -rf $(BUILD_DIRECTORY)
