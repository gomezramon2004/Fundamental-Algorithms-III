CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
BSTDIR = bst
TSTDIR = testcase
UIDIR = interface
LNKDIR = linkedList

SRCS = main.cpp \
		$(BSTDIR)/bst.cpp \
		$(LNKDIR)/linkedList.cpp \
		$(UIDIR)/interface.cpp \

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean