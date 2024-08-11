# Define directories
APP_DIR = app
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
TEST_DIR = test
BIN_DIR = bin

# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -fPIC
LDFLAGS = -L$(LIB_DIR) -lgeo -Wl,-rpath=$(LIB_DIR) -lboost_iostreams -lm


# Find source files and define object files
SRC_FILES = $(shell find $(SRC_DIR) -name "*.cpp")
APP_FILES = $(shell find $(APP_DIR) -name "*.cpp")
TEST_FILES = $(shell find $(TEST_DIR) -name "*.cpp")

SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
APP_OBJ_FILES = $(patsubst $(APP_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(APP_FILES))
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_FILES))

LIB_NAME = libgeo.so

# Define targets
all: lib app unittest

lib: $(SRC_OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared $(SRC_OBJ_FILES) -o $(LIB_DIR)/$(LIB_NAME) 

app: $(APP_OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(APP_OBJ_FILES) $(LDFLAGS) -o $(BIN_DIR)/app.out

unittest: $(TEST_OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ_FILES) $(LDFLAGS) -o $(BIN_DIR)/unittest.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(APP_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean

set:
	echo "Setting LD_LIBRARY_PATH"
	export LD_LIBRARY_PATH=/home/shinigami/coding/assignments/cs206/lib:$LD_LIBRARY_PATH

run:
	./$(BIN_DIR)/app.out

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/*.so $(BIN_DIR)/*.out
