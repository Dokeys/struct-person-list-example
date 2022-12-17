/*
 * main.c
 *
 *  Created on: 16.12.2022
 *      Author: Dominik Knoll
 *
 *  Description:
 *  This is a simple example of the struct pattern in c.
 *  person_t can be used like an object. The objects can be stored in an person_list_t object.
 *  Dynamic memory allocation is used for the most of the stuff.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "person_list.h"

int main(int argc, char **argv) {
	person_t dome, klaus, petra;
	init_person(&dome, "Dominik", "Knoll", 32);
	init_person(&klaus, "Klaus", "Kleber", 66);
	init_person(&petra, "Petra", "Schmitt", 35);

	person_list_t list;
	init_person_list(&list);
	add_person_to_person_list(&list, &dome);
	add_person_to_person_list(&list, &klaus);
	add_person_to_person_list(&list, &petra);

	print_person_list(&list);

	return 0;
}
