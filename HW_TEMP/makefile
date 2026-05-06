# Переменные
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = temp_app
SRCS = temp_api.c

OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = temp_api.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compile C files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# Run rule
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run