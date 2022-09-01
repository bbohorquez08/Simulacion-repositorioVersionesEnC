all: main.o
	gcc -o versions main.o
main.o: main.c
	gcc -c -o main.o main.c
clean:
	rm -f versions main.o
clean-repo:
	rm -rf .versions
clean-all:
	rm -rf .versions
	rm -f versions main.o
	clear

install: all
	sudo cp versions /usr/local/bin

uninstall:
	sudo rm -f /usr/local/bin/versions