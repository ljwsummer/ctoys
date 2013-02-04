
GCC = g++ -O3 -lm -Wall

ctoys:
	$(GCC) -o hello hello.c
	$(GCC) -o remove_node remove_node.c

clean:
	rm hello
	rm remove_node

