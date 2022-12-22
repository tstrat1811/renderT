CC = g++
CFLAGS = -c -Wall

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, obj/%.o, $(SOURCES))

renderT: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ -ldl -lglfw

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f obj/*.o renderT

echoes:
	@echo "INC files: $(SOURCES)"
	@echo "OBJ files: $(OBECTJS)"