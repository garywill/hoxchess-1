####################################################################
# The 'Makefile' of TSITO AI Engine.
#
####################################################################

# The name of the App.
LIBRARY = AI_TSITO

# Common flags
CXX         = g++

CXXFLAGS = -fPIC -Wall -I../common
#DEBUGFLAGS  = -g

# The main source
MAIN_SRC := \
	AI_TSITO.cpp \
	Evaluator.cpp \
	Move.cpp \
	Options.cpp \
	Transposition.cpp \
	Board.cpp \
	Lawyer.cpp \
	OpeningBook.cpp \
	Timer.cpp \
	tsiEngine.cpp

# Define our sources and object files
SOURCES := \
	$(MAIN_SRC)

OBJECTS := $(SOURCES:.cpp=.o)

.cpp.o :
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c -o $@ $<

all: $(LIBRARY)
	cp -v libAI_TSITO.so.1.0 ../AI_TSITO.so

$(LIBRARY): $(OBJECTS)
	$(CXX) -shared -Wl,-soname,lib$(LIBRARY).so.1 -o lib$(LIBRARY).so.1.0 $(OBJECTS)

clean:
	rm -vrf lib$(LIBRARY).* *.o

############## END OF FILE ###############################################

