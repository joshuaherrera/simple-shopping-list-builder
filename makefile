###
### file - makefile
### author - Joshua Herrera
### description - makefile for use in CS162. Modified from a Harlan James' 
### makefile example.
###

PROJECT = shopping_list
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

VAL = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

SRCS = project02Driver.cpp Item.cpp List.cpp Menu.cpp utilities.cpp

HEADERS = utilities.hpp Item.hpp List.hpp Menu.hpp

OBJS = $(SRCS:.cpp=.o)

BIN = ${PROJECT}.bin

default: clean ${BIN} 

debug: clean ${BIN}
	valgrind ${VAL} ./${BIN}

${BIN}: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} ${CXXFLAGS} -o ${BIN}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

zip:
	zip -D ${PROJECT}.zip *.cpp *.hpp *.pdf makefile

clean: $(CLEAN)
	@echo "Remove	*.o"
	@echo "Remove	$(BIN)"
	@rm -f *.o $(BIN)