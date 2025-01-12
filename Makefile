CC = gcc
CFLAGS = -g -Wall -fprofile-arcs
TARGET = conta_palavras

all: $(TARGET)

$(TARGET): conta_palavras.c testa_conta_palavras.c
	$(CC) $(CFLAGS) -o $(TARGET) conta_palavras.c testa_conta_palavras.c

clean:
	rm -f $(TARGET)
