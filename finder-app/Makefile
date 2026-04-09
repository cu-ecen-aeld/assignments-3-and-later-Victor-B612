# specify cross-compiler
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror

#Source and tarjet
SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)

#Default tarjet
all: $(TARGET)

#Linking rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

#Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and target executable
clean:
	rm -f $(TARGET) *.o