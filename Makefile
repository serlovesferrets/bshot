BUILD_DIR := ./build
PROJ_DIR := .

SRCS := $(shell find $(PROJ_DIR) -name '*.c') 

TARGET_EXEC := arduino

make:
	@mkdir -p build
	clang -o $(BUILD_DIR)/$(TARGET_EXEC) $(SRCS)

run: 
	@make
	$(BUILD_DIR)/$(TARGET_EXEC)

clean:
	rm -rf $(BUILD_DIR)
