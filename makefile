CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
BSTDIR = bst
TSTDIR = testcase
UIDIR = interface
LNKDIR = linkList

SRCS = main.cpp \
		$(BSTDIR)/bst.cpp \
		$(TSTDIR)/testcase.cpp \
		$(LNKDIR)/linkList.cpp \
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