COMPILER = g++
#COMPILER = clang++
#COMPILER = g++-4.4
CFLAGS    = -g -MMD -MP -Wall -Wextra -Winit-self -Wno-unused-parameter -Wfloat-equal -std=c++11
CFLAGS   += -O1 -O2 -O3
CFLAGS   += `root-config --cflags`
LDFLAGS   =
LDFLAGS  += `root-config --libs`
LIBS      =
INCLUDE   = -I../include
INSTALL_DIR = ~/bin

TARGET   = tb

SOURCES  = $(wildcard *.cc)
OBJECTS  = $(SOURCES:.cc=.o)
DEPENDS  = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

install: $(TARGET)
	install -s $(TARGET) $(INSTALL_DIR)

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

-include $(DEPENDS)
