CC=g++
FALGS=-std=c++14 -W -O2

all:main

main:main.cxx TOTP.cxx
	$(CC) $(FALGS) -o main main.cxx TOTP.cxx -lssl -lcrypto -ldl -lpthread

clean:
	rm -f main
