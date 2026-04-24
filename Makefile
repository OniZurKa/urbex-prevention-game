# ========================
# Détection de l'OS
# ========================
ifeq ($(OS),Windows_NT)
    OS_NAME := Windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        OS_NAME := MacOS
    else
        OS_NAME := Linux
    endif
endif

# ========================
# Projet
# ========================
NAME := urbex

# ========================
# Dossiers
# ========================
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INC_DIR := include
HDR_DIR := src/headers
LIB_DIR := lib/raylib

# 👉 Chemin vers la lib compilée
RAYLIB_BUILD := $(LIB_DIR)/build/raylib

# ========================
# Fichiers
# ========================
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# ========================
# Compilateur
# ========================
CC := gcc

# ========================
# Flags
# ========================
CFLAGS := -Wall -Wextra -I$(INC_DIR) -I$(HDR_DIR) -I$(LIB_DIR)/include

# ========================
# Configuration selon OS
# ========================
ifeq ($(OS_NAME),Windows)
    BIN := $(BIN_DIR)/$(NAME).exe
    RPATH_FLAG :=
    LDFLAGS := -L$(RAYLIB_BUILD) -lraylib -lopengl32 -lgdi32 -lwinmm -static

else ifeq ($(OS_NAME),MacOS)
    BIN := $(BIN_DIR)/$(NAME)
    RPATH_FLAG := -Wl,-rpath,@loader_path/../$(RAYLIB_BUILD)
    LDFLAGS := -L$(RAYLIB_BUILD) -lraylib \
        -framework OpenGL \
        -framework Cocoa \
        -framework IOKit \
        -framework CoreAudio \
        -framework CoreVideo \
        $(RPATH_FLAG)

else
    BIN := $(BIN_DIR)/$(NAME)
    RPATH_FLAG := -Wl,-rpath,'$$ORIGIN/../$(RAYLIB_BUILD)'
    LDFLAGS := -L$(RAYLIB_BUILD) -lraylib \
        -lm -ldl -lpthread -lGL -lrt \
        $(RPATH_FLAG)
endif

# ========================
# Règles
# ========================
all: $(BIN)

$(BIN): $(OBJ)
ifeq ($(OS_NAME),Windows)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	mkdir -p $(BIN_DIR)
endif
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
ifeq ($(OS_NAME),Windows)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
else
	mkdir -p $(OBJ_DIR)
endif
	$(CC) $(CFLAGS) -c $< -o $@

run: all
ifeq ($(OS_NAME),Windows)
	$(BIN)
else
	./$(BIN)
endif

clean:
ifeq ($(OS_NAME),Windows)
	@cmd /C "if exist \"$(BIN)\" del /F /Q \"$(BIN)\""
	@if exist "$(OBJ_DIR)" rmdir /S /Q "$(OBJ_DIR)"
else
	rm -rf $(OBJ_DIR)
	rm -f $(BIN)
endif

re: clean all

.PHONY: all run clean re