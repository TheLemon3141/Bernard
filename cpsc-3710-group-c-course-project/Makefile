CXX = g++
CXXFLAGS = -O2 -std=c++14

LIBS = -lglut -lGLU -lGL -lm -lGLEW

#SRC   = lodepng/lodepng.cpp src/camera.cpp src/painter.cpp src/zbuffer.cpp src/main.cpp
SRC = main.cc
HDR = include/*.h
BIN = bernard

all: $(BIN)

$(BIN): $(SRC) $(HDR)
#	$(CXX) $(CXXFLAGS) -o $@ $(SRC) $(LIBS) # the flags make Bernard disappear
# $(CXX) -o $@ $(SRC)-I include/*.h $(LIBS)
	$(CXX) -o $@ $(SRC) $(LIBS)

clean:
	rm -f $(BIN)

# gcc main.cc -lglut -lGLU -lGL -lm -lGLEW -o bernard
# ./bernard