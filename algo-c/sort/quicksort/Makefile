obj= qsort.o test.o

qsort: $(obj)
	cc -o qsort $(obj)

*.o: *.c
	cc -c *.c

clean:
	rm *.o obj
