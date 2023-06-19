# Paths
SRCDIR := src
IDIR := include
OBJDIR := obj
BINDIR := bin

# Make arguments
MAKEFLAGS += --jobs=$(shell nproc) --output-sync=target

# Compiler and flags
CXX := g++
CXXDBGFLAGS += -g -fdiagnostics-color=always
CXXFLAGS += -std=c++17 $(CXXDBGFLAGS) $(CXXWARN)
CXXWARN += -Wno-deprecated-declarations -Wall -Wextra -pedantic -Weffc++
LDFLAGS += -lSDL2 -lGL -lSDL2_image

# Rule variables
TARGET := main
SRCS := $(shell find $(SRCDIR) -name '*.cpp')
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(SRCS))

all: $(BINDIR)/$(TARGET)

# Colors
COLOR_GREEN = '\033[0;32m'
COLOR_RED   = '\033[0;31m'
COLOR_RESET = '\033[0m'

# Link the final binary.
$(BINDIR)/$(TARGET): $(OBJS) Makefile dir
	@echo -e Creating $(COLOR_RED)$@$(COLOR_RESET)
	@$(CXX) $(OBJS) -o $(BINDIR)/$(TARGET) $(LDFLAGS)

# Compile everything.
-include $(DEPS)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo -e Compiling $(COLOR_GREEN)$<$(COLOR_RESET)
	@$(CXX) -I$(IDIR) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Run the game
run: $(BINDIR)/$(TARGET)
	@./$(BINDIR)/$(TARGET)

# Create required directories
dir:
	@mkdir -p $(BINDIR)

# Remove all non-source files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean dir run
