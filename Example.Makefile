CC=gcc
CXX=g++
DBG_CXXFLAGS=-O2 -Wall -Wno-sign-compare
OPT_CXXFLAGS=-O2 -Wall -Wno-sign-compare
INCLUDES=-I./src
LINK=src/libsla.a

all: sleighexample


sleighexample.o: sleighexample.cc
	$(CXX) -c $(DBG_CXXFLAGS) $(INCLUDES) $< -o $@

sleighexample: sleighexample.o
	$(CXX) $(DBG_CXXFLAGS) -o sleighexample sleighexample.o $(LINK)

clean:
	rm -rf *.o sleighexample
