obj = drlist.o test.o

ltest: $(obj)
	cc -o ltest $(obj)

drlist.o: drlist.c
	cc -c drlist.c
test.o: test.c
	cc -c test.c

clean:
	rm *.o obj
