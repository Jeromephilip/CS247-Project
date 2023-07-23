CXX=g++
CXXFLAGS=-std=c++14 -Wall -g -MMD
EXEC=main
SRCDIR=.
OBJDIR=obj

# Find all .cc files in all subdirectories of SRCDIR
SRCFILES=$(wildcard $(SRCDIR)/**/*.cc)

# Add main.cc to the source files list
SRCFILES+=$(wildcard $(SRCDIR)/main.cc)

# Generate the corresponding .o file names in OBJDIR
OBJECTS=$(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SRCFILES))

DEPENDS=$(OBJECTS:.o=.d)

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

-include $(DEPENDS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(EXEC)