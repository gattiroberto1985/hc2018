
# project name (generate executable with this name)
TARGET   = hc2018

CC       = gcc -std=c99 -c
# compiling flags here
CFLAGS   = -Wall -I.

LINKER   = gcc -o
# linking flags here
LFLAGS   = -Wall

# change these to proper directories where each file should be
#SOURCES  := $(wildcard *.c)
#INCLUDES := $(wildcard *.h)
#OBJECTS  := $(SOURCES:.c=*.o)
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
    @$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
    @echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
    @$(CC) $(CFLAGS) -c $< -o $@
    @echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
    @$(rm) $(OBJECTS)
    @echo "Cleanup complete!"

.PHONY: remove
remove: clean
    @$(rm) $(BINDIR)/$(TARGET)
    @echo "Executable removed!"
