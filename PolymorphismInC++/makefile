# CXX is a standard variable name used for the compiler. 
CXX = g++

# CXXFLAGS is a standard variable name for compile flags.
# -std=c++0x specifies to use a certain language version.
CXXFLAGS = -std=c++11

# -Wall turns on all warnings
#CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
#CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files. 
# Edit as needed.
SRC1 = main.cpp
SRC2 = creature.cpp
SRC3 = medusa.cpp
SRC4 = blueMen.cpp
SRC5 = gollum.cpp
SRC6 = harryPotter.cpp
SRC7 = reptilePeople.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7}

# HEADERS is a standard name for the header files. 
# Edit these as needed.
HEADER1 = creature.hpp
HEADER2 = medusa.hpp
HEADER3 = blueMen.hpp
HEADER4 = gollum.hpp
HEADER5 = harryPotter.hpp
HEADER6 = reptilePeople.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6}

# These will be your executable names. 
# Edit as needed.
PROG1 = A3_wolfe
#PROG2 = 
PROGS = ${PROG1} 

# This is the name of your document(s). 
# Edit as needed.
DOC = ASSIGNMENT-3_DWOLFE_CS162-400.pdf

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
#TAR = cs162-400_assignment1_username.tar.bz2
TAR = cs162-400_A3_dWolfe.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build availible.
# In this case, default.
default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

