MAIN = address_book_main
INPUT = address_book_input
IO = address_book_io_functions
LLFUNCTIONS = address_book_linked_list_functions
COMPILER = gcc
COMPILERFLAGS = -c

all: $(MAIN)

$(MAIN): $(INPUT).o $(IO).o $(LLFUNCTIONS).o $(MAIN).o
	$(COMPILER) $(INPUT).o $(IO).o $(LLFUNCTIONS).o $(MAIN).o -o c_address_book

$(MAIN).o: $(MAIN).c record.h
	$(COMPILER) $(COMPILERFLAGS) $(MAIN).c

$(INPUT).o: $(INPUT).c
	$(COMPILER) $(COMPILERFLAGS) $(INPUT).c

$(IO).o: $(IO).c record.h
	$(COMPILER) $(COMPILERFLAGS) $(IO).c

$(LLFUNCTIONS).o: $(LLFUNCTIONS).c record.h
	$(COMPILER) $(COMPILERFLAGS) $(LLFUNCTIONS).c

clean:
	rm -f *.o c_address_book
