CC = g++
CFLAGS = -c -Wall
LDFLAGS = -ldl -lglfw


SOURCES = $(wildcard *.cpp */*.cpp)

OBJECTS = $(patsubst %/%.cpp, ../obj/%.o, $(SOURCES))

renderT: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

../obj/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f ../obj/*.o renderT
