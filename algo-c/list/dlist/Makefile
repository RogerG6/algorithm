obj = dlist.o test.o

ltest: $(obj)
	cc -o ltest $(obj)

dlist.o: dlist.c
	cc -c dlist.c
test.o: test.c
	cc -c test.c

clean:
	rm *.o obj
