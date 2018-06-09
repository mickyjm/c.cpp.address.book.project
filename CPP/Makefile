all: main llist input display
	g++ -o project_02 project_02_main.o llist.o project_02_get_input.o project_02_display_messages.o

main:
	g++ -c -s project_02_main.cpp

llist:
	g++ -c -s llist.cpp

input:
	g++ -c -s project_02_get_input.cpp

display:
	g++ -c -s project_02_display_messages.cpp

debug: main_debug llist input display
	g++ -o project_02_DEBUG project_02_main.o llist.o project_02_get_input.o project_02_display_messages.o

main_debug:
	g++ -c -s -DDEBUG  project_02_main.cpp

clean:
	rm -rf *.o
