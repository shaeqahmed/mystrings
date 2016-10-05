strtest: mystrings.c
	gcc mystrings.c -o strtest

clean:
	rm *~	

run: strtest
./strtest