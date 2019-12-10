principal: 
	gcc main.c -o principal
main.o:
	gcc -c main.c
clean:
	rm *.o