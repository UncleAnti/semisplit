
.PHONY: all clean
all: SemiSplit

clean:
	$(RM) *.o SemiSplit

main.o: main.cpp semisplit.h
	$(CXX) -c -o $@ $<

SemiSplit: main.o
	$(CXX) -o $@ $<
