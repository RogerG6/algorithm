obj = srlist.o test.o

ltest: $(obj)
	cc -o ltest $(obj)

srlist.o: srlist.c
	cc -c srlist.c
test.o: test.c
	cc -c test.c

clean:
	rm *.o obj
