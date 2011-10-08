all: spirit spiritgui
%.o: %.c afc.h
	gcc -std=gnu99 -c `pkg-config --cflags gtk+-2.0` -I/usr/include/glib-2.0 -o $@ $<

spirit: spirit.o afc.o spiritgui.c
	gcc -o spirit spirit.o afc.o -limobiledevice -lplist -lcrypto

spiritgui: spiritgui.o
	gcc -o spiritgui spiritgui.o `pkg-config --libs gtk+-2.0`

clean:
	rm -rf spirit spiritgui *.o *.dSYM
