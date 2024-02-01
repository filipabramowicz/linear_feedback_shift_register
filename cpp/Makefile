.PHONY: all
all: test

.PHONY: test
test:
	g++ -I src/ src/lfsr.cpp test/lfsr_test.cpp -o test.out -lCppUTest
	./test.out

.PHONY: clean
clean:
	rm -rf *.out