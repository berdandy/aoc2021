SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))

.PHONY: all clean test

all: $(PROGS)

%: %.cpp %.h
	$(CXX) $(CXXFLAGS)  -o $@ $<

test: $(PROGS)
	@for test in $^; do ./$${test}; done

clean:
	rm $(PROGS)

