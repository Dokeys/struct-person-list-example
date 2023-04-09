bin/program: build/main.o build/person.o build/person_list.o 
	gcc build/main.o build/person.o build/person_list.o -o bin/program	

build/main.o: main.c
	gcc main.c -c -Iinc/ -o build/main.o

build/person.o: src/person.c
	gcc src/person.c -c -Iinc/ -o build/person.o

build/person_list.o: src/person_list.c
	gcc src/person_list.c -c -Iinc/ -o build/person_list.o

clean:
	rm build/*
