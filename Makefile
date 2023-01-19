CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Werror=return-type  -Werror=uninitialized 

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.hpp=%.o)

CATCH = test/catch/catch.o
TEST_SRCS = $(wildcard test/*.cpp)
TESTS = $(TEST_SRCS:test/%.cpp=%)
#TESTS := $(shell find ./test -name "*cpp")

main: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(addprefix test/,$(TESTS)) core main $(CATCH)

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-all: $(TESTS)
test-1-user: test/test-1-user.cpp user.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-2-vin: test/test-2-vin.cpp vigenere.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-3: test/test-3.cpp passgen.o vigenere.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-4: test/test-4.cpp user.o list.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success