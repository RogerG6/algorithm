obj= isort.o test.o

insertsort: $(obj)
	cc -o insertsort $(obj)

*.o: *.c
	cc -c *.c

clean:
	rm *.o insertsort 
