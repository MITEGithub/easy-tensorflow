CC = g++
CFLAGS = -std=c++11 -O0 -g

AR = ar 
AFLAGS =-rc

SRC_DIR = src
INC_DIR = include
BIN_DIR = build

SRCS = $(shell find src -type f -name "*.cc")
HEADERS = $(shell find include -type f -name "*.h")
OBJS = $(patsubst src/%.cc, build/%.o, $(SRCS))
LIB_OBJS = $(filter-out build/main.o, $(OBJS))


TARGET = main

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cc $(HEADERS)
	@mkdir -p -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(BIN_DIR)
	rm ./test/correct ./test/correct.txt ./test/test ./test/test.txt

run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET)

pack: $(LIB_OBJS)
	$(AR) $(AFLAGS) $(BIN_DIR)/libeasytf.a $(LIB_OBJS)

gdb: $(BIN_DIR)/$(TARGET)
	gdb $(BIN_DIR)/$(TARGET)

.PHONY: all clean run
