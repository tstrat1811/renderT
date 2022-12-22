TARGET = renderT

CC = g++
CFLAGS = -g

OUTDIR = ..
SUBDIR = ../src
DIR_OBJ = ../obj

INCS = $(wildcard *.h) $(foreach fd, $(filter-out .,$(SUBDIR)), $(fd)/*.h)
SRCS = $(wildcard *.cpp) $(foreach fd, $(filter-out .,$(SUBDIR)), $(fd)/*.cpp)
NODIR_SRC = $(notdir $(SRCS))
OBJS = $(addprefix $(DIR_OBJ)/, $(NODIR_SRC:cpp=o)) # obj/xxx.o obj/folder/xxx .o
INC_DIRS = $(addprefix -I, $(SUBDIR))

.PHONY: clean echoes

$(TARGET): $(OBJS)
	$(CC) -o $(OUTDIR)/$@ $(OBJS) -ldl -lglfw

$(DIR_OBJ)/%.o: %.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS) $(INC_DIRS) 
clean:
	rm -rf $(OUTDIR)/$(TARGET) $(DIR_OBJ)/*

echoes:
	@echo "INC files: $(INCS)"  
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"