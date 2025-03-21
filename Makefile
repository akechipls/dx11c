CC = gcc
CFLAGS = -Wall -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um"
LDFLAGS = -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64" -ld3d11 -ldxgi

SRC = main.c
OUT = dx11_app.exe

all:
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(OUT)