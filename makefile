project: project.o linked_list.o
	gcc project.o linked_list.o -o project
linked_list.o: linked_list.c
	gcc -c linked_list.c
project.o: project.c
	gcc -c project.c