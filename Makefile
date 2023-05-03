CC = g++
CXXFLAGS = -std=c++11
LDFLAGS = -lncurses
TARGETS = MAIN MainEngine
OBJDIR = ./obj

all: $(TARGETS)

MAIN: $(OBJDIR)/MAIN.o $(OBJDIR)/doorcoordinate.o $(OBJDIR)/MainEngine.o $(OBJDIR)/Map_loading.o
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

MainEngine: $(OBJDIR)/MainEngine.o $(OBJDIR)/Map_loading.o
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/MAIN.o: Main_directory/MAIN.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/doorcoordinate.o: CharactersDesign_Mechanism/doorcoordinate.cpp CharactersDesign_Mechanism/doorcoordinate.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/MainEngine.o: CharactersDesign_Mechanism/MainEngine.cpp CharactersDesign_Mechanism/MapLoader.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Map_loading.o: Map_Objects/Map_loading.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(TARGETS)


