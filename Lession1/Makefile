GXX = g++
TARGET = hello
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))

GXXFLAG = -c -Wall

$(TARGET):$(OBJ)
	-$(GXX) -o $@ $^
	-./$@
	-rm *.o

%.o:%.cpp
	$(GXX) $(GXXFLAG) $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(OBJ)