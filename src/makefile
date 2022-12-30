CC = g++
CFLAGS = -c -Wall
LDFLAGS = -ldl -lglfw
IMGUI_DIR = ./imgui


SOURCES = $(wildcard *.cpp */*.cpp)

OBJECTS = $(addprefix ../obj/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))


renderT: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

../obj/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

../obj/%.o: $(IMGUI_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f ../obj/*.o renderT

echoes:
	@echo "INC files: $(SOURCES)"
	@echo "OBJ files: $(OBJECTS)"
