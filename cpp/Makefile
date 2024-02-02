.PHONY: all
all: test

.PHONY: product
product:
	g++ -I src/ -g src/lfsr.cpp src/main.cpp -o main.out
	./main.out

.PHONY: test
test:
	g++ -I src/ src/lfsr.cpp test/lfsr_test.cpp -o test.out -lCppUTest
	./test.out

.PHONY: clean
clean:
	rm -rf *.out