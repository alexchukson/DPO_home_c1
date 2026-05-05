# Переменные
CC = cl.exe
CFLAGS = /nologo /W4 /EHsc
TARGET = temp_app
SRCS = temp_api.c

OBJS = $(SRCS:.c=.obj)

# Header files
HEADERS = temp_api.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) /Fe:$(TARGET)

# Compile C files - works for both debug and release
%.obj: %.c $(HEADERS)
	$(CC) $(CFLAGS) /c $< /Fo$@

# temp_api.obj: temp_api.c $(HEADERS)
# 	$(CC) $(CFLAGS) /c $< /Fo$@