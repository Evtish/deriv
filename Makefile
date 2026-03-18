PROGRAM_NAME := main

SRC_DIR := src
INC_DIR := inc
BUILD_DIR := build

SOURCE_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJECT_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE_FILES))
DEPENDENCY_FILES := $(OBJECT_FILES:.o=.d)
EXEC_FILE := $(BUILD_DIR)/$(PROGRAM_NAME)

CC := cc
CFLAGS := -Wall -Wextra -std=c99 -pedantic -I$(INC_DIR) -save-temps=obj
LDFLAGS := -lm

all: $(EXEC_FILE)

# Create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Check if the build directory exists
$(OBJECT_FILES): | $(BUILD_DIR)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

-include $(DEPENDENCY_FILES)

# Link
$(EXEC_FILE): $(OBJECT_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

# Run the executable
run: $(EXEC_FILE)
	./$(EXEC_FILE)

# Remove the build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
