bsb.so: lua_bsb_io.o bsb_fastio.o
	$(CC) $(LDFLAGS) -shared -nostartfiles  -Wl,-soname,bsb.so\
		-o bsb.so lua_bsb_io.o bsb_fastio.o -llua -lm -ldl 
bsb_fastio.o: bsb_fastio.c
	$(CC) $(CFLAGS) -std=gnu99 -fPIC -c bsb_fastio.c
lua_bsb_io.o: 
	$(CC) $(CFLAGS) -fPIC -llua -c lua_bsb_io.c 
.PHONY: clean
clean:
	rm -f *.o bsb.so
