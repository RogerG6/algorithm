obj= binary.o test.o

b_search: $(obj)
	cc -o b_search $(obj)

*.o: *.c
	cc -c *.c

clean:
	rm *.o b_search 
