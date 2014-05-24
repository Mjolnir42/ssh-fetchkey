# vim: set ft=make ffs=unix fenc=utf8:
# vim: set noet ts=4 sw=4 tw=72 list:
all: build

build:
	@gcc -std=gnu99 ssh-fetchkey.c -o ssh-fetchkey -lssh

clean:
	@rm -f ssh-fetchkey
