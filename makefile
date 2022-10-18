SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))
CXXFLAGS := -std=c++17 -Wall

main: $(BIN_FILES)
	g++ -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CXXFLAGS) -c $^

CXXFLAGS += -MMD
-include $(OBJ_FILES:.o=.d)