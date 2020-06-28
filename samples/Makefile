.PHONY: all clean

vpath %.hpp ../include

INCLUDES = ../include
CPPFLAGS = -I"$(INCLUDES)"
CXXFLAGS = -std=c++17
CC = $(CXX)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(subst .cpp,.o,$(SOURCES))
TARGETS = $(patsubst %.cpp,%,$(SOURCES))
TARGETS_WIN = $(subst .cpp,.exe,$(SOURCES))

all: $(TARGETS)

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

clean:
	rm $(OBJECTS) $(TARGETS) $(TARGETS_WIN) 2> /dev/null || true

include $(subst .cpp,.d,$(SOURCES))
