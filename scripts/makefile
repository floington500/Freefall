CC := g++
CFLAGS := -I../include
SRC_DIR := ../src
BUILD_DIR := ../build

SRCS := $(wildcard $(SRC_DIR)/*.cc)
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: freefall data_out

freefall: $(BUILD_DIR)/main.o $(BUILD_DIR)/math.o
	$(CC) $^ -o $(BUILD_DIR)/$@

data_out: $(BUILD_DIR)/data_out.o $(BUILD_DIR)/math.o
	$(CC) $^ -o $(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR)/*

run_freefall: freefall
	./$(BUILD_DIR)/freefall

run_data_out: data_out
	./$(BUILD_DIR)/data_out
