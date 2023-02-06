CXXFLAGS := -std=c++17
LINK.o := $(CXX) $(CXXFLAGS)

.PHONY: all clean handin

driver : driver.o

driver.o : driver.cpp sort.hpp

handin : handin.tar

handin.tar : driver.cpp sort.hpp
	tar cvf $@ $^

all : driver handin

clean :
	rm -f driver driver.o handin.tar
