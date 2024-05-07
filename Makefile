BUILD_DIR := ./build
PROJ_DIR := .
LIBS_DIR := $(PROJ_DIR)/libs

make:
	@mkdir -p build
	clang -o $(BUILD_DIR)/main $(PROJ_DIR)/arduino.c $(LIBS_DIR)/randgen.c

run: 
	@make
	$(BUILD_DIR)/main

clean:
	rm -rf $(BUILD_DIR)
