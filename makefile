all: funktional.o

CXX ?= g++-9

CXXFLAGS ?= --std=c++2a --all-warnings --extra-warnings -Wno-address \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-Warray-bounds -Wattribute-alias -Wformat-overflow -Wformat-truncation \
	-Wmissing-attributes -Wstringop-truncation \
	-O1

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
