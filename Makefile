CC = gcc

# inclui o config.mk com o caminho da raylib
-include config.mk

ifndef RAYLIB_PATH
$(error Crie um arquivo config.mk com o caminho da sua instalação da raylib)
endif

TARGET = To-Do-List.exe

SRC = $(wildcard src/*.c)

CPPFLAGS = -Iinclude -I"$(RAYLIB_PATH)"
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -mconsole -L"$(RAYLIB_PATH)"
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

.PHONY: all run clean

all:
	$(CC) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del /Q $(TARGET)