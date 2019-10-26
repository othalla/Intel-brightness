ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

default: all

brightness: brightness.c
	gcc brightness.c -o brightness


.PHONY: all clean install
all: brightness

clean:
	@rm -f ./brightness

install:
	cp ./brightness $(PREFIX)/bin/brightness
	chown root:root $(PREFIX)/bin/brightness
	chmod +s $(PREFIX)/bin/brightness