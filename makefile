all: test test3d

test: openglTest.cpp
	g++ openglTest.cpp -l sfml-system -l sfml-window -l sfml-graphics -l OpenGL -o test

test3d: opengl3DTest.cpp
	g++ opengl3DTest.cpp -l sfml-system -l sfml-window -l sfml-graphics -l OpenGL -o test3d
