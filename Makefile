CXX  = g++
TARGET = main
CXXFLAGS = -W
OBJECTS = main.o library.o member.o resource.o


$(TARGET) :  $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c $^

library.o : library.cpp
	$(CXX) $(CXXFLAGS) -c $^

member.o : member.cpp
	$(CXX) $(CXXFLAGS) -c $^

resoucre.o : resource.cpp
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm -f *.o library .*.swp



