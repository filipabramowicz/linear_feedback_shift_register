.PHONY: all
all: product test

.PHONY: product
product:
	cc -I src/ -g src/lfsr.c src/main.c -o main.out
	./main.out

.PHONY: test
test:
	cc -I ../cmocka-1.1.7/include/ -I src/ -L ../cmocka-1.1.7/build/src/ -g src/lfsr.c test/test_lfsr.c -lcmocka -o test.out
	./test.out

.PHONY: clean
clean:
	rm -rf *.out