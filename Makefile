all: sfml-app
	./sfml-app

sfml-app: main.o Player.o
	g++ -std=c++17 -o sfml-app main.o Player.o  -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

Player.o: Player.cpp Player.h
	g++ -std=c++17 -c Player.cpp

main.o : main.cpp Player.h
		g++ -std=c++17 -c main.cpp

clean:
	rm -rf *o sfml-app
