obj = slist.o test.o

ltest: $(obj)
	cc -o ltest $(obj)

slist.o: slist.c
	cc -c slist.c
test.o: test.c
	cc -c test.c

clean:
	rm *.o obj
