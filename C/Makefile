MAIN = project_01_main
DISPLAY = project_01_display_messages
INPUT = project_01_get_input
IO = project_01_iofunctions
DBINTERACTION = project_01_database
COMPILER = gcc
COMPILERFLAGS = -c

all: $(MAIN)

$(MAIN): $(DISPLAY).o $(INPUT).o $(IO).o $(DBINTERACTION).o $(MAIN).o
	$(COMPILER) $(DISPLAY).o $(INPUT).o $(IO).o $(DBINTERACTION).o $(MAIN).o -o project_01

$(MAIN).o: $(MAIN).c record.h
	$(COMPILER) $(COMPILERFLAGS) $(MAIN).c

$(DISPLAY).o: $(DISPLAY).c
	$(COMPILER) $(COMPILERFLAGS) $(DISPLAY).c

$(INPUT).o: $(INPUT).c
	$(COMPILER) $(COMPILERFLAGS) $(INPUT).c

$(IO).o: $(IO).c record.h
	$(COMPILER) $(COMPILERFLAGS) $(IO).c

$(DBINTERACTION).o: $(DBINTERACTION).c record.h
	$(COMPILER) $(COMPILERFLAGS) $(DBINTERACTION).c

clean:
	rm -f *.o project
