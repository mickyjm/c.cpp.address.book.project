MAIN = address_book_main
FUNCTIONS = address_book
LLFUNCTIONS = llist
COMPILER = g++
COMPILERFLAGS = -c -s
DEBUG = -DDEBUG

all: $(MAIN)

debug: $(MAIN)_debug

$(MAIN): $(FUNCTIONS).o $(LLFUNCTIONS).o $(MAIN).o
	$(COMPILER) $(FUNCTIONS).o $(LLFUNCTIONS).o $(MAIN).o -o cpp_address_book

$(MAIN).o: $(MAIN).cpp
	$(COMPILER) $(COMPILERFLAGS) $(MAIN).cpp

$(FUNCTIONS).o: $(FUNCTIONS).cpp $(FUNCTIONS).h
	$(COMPILER) $(COMPILERFLAGS) $(FUNCTIONS).cpp

$(LLFUNCTIONS).o: $(LLFUNCTIONS).cpp $(LLFUNCTIONS).h record.h
	$(COMPILER) $(COMPILERFLAGS) $(LLFUNCTIONS).cpp

$(MAIN)_debug: $(FUNCTIONS)_debug.o $(LLFUNCTIONS)_debug.o $(MAIN)_debug.o
	$(COMPILER) $(FUNCTIONS)_debug.o $(LLFUNCTIONS)_debug.o $(MAIN)_debug.o -o cpp_address_book_debug

$(MAIN)_debug.o: $(MAIN).cpp
	$(COMPILER) $(COMPILERFLAGS) $(DEBUG) $(MAIN).cpp -o $(MAIN)_debug.o

$(FUNCTIONS)_debug.o: $(FUNCTIONS).cpp $(FUNCTIONS).h
	$(COMPILER) $(COMPILERFLAGS) $(DEBUG) $(FUNCTIONS).cpp -o $(FUNCTIONS)_debug.o

$(LLFUNCTIONS)_debug.o: $(LLFUNCTIONS).cpp $(LLFUNCTIONS).h record.h
	$(COMPILER) $(COMPILERFLAGS) $(DEBUG) $(LLFUNCTIONS).cpp -o $(LLFUNCTIONS)_debug.o

clean:
	rm -f *.o cpp_address_book*
