# Makefile fore writing make files example
# *****************************************************************************
# Variables to control Makefile operation

CC= g++
SRCDIR=src
INCDIR=inc
EXEC = main
BUILDDIR=build
TARGET=./bin/$(EXEC)

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS = -Wall -std=c++11 -fexceptions -g
LIB= lib/glfw-3.2.1/src/libglfw3.a -lGLEW -lm -lGLU -lGL -ldl -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lXinerama -lXcursor
INC= -I lib/glfw-3.2.1/include/ -L /usr/local/lib/  -I $(INCDIR)
# *****************************************************************************
# Targets needed to bring executable up to date

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ $(LIB) -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " find $(BUILDDIR) -name '*.o' -delete"
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; find $(BUILDDIR) -name '*.o' -delete

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean
