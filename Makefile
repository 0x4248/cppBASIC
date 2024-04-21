# cppBASIC
# A simple BASIC like interpreter in C++
# Github: https://www.github.com/0x4248/cppBASIC
# Licence: GNU General Public License v3.0
# By: 0x4248

CXX = g++

SRC_DIR = src
INC_DIR = include
BUILD_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
INC_FLAGS = -I$(INC_DIR)

CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

TARGET = cppBASIC

$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | init
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

init:
	mkdir -p $(BUILD_DIR)


.PHONY: init clean

clean:
	rm -rf $(BUILD_DIR)

