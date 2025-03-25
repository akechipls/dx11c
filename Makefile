CC = gcc
CFLAGS = -Wall -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um" -I.
LDFLAGS = -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64" -ld3d11 -ldxgi
EXE_NAME = dx11_app

SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
EXEC = $(BIN_DIR)/$(EXE_NAME)

all: $(EXEC) clean # checks if $(EXEC) is different from source code

$(EXEC): $(OBJS) #target:dependencies and below are comands to run if the obj files are different or the exe doesn't exist
	$(CC) $(CFLAGS)  $^ -o $(EXEC) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm $(OBJ_DIR)/*.o