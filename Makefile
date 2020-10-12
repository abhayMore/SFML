all: sfml-app
	./sfml-app

sfml-app: main.o Player.o Fruit.o
	g++ -std=c++17 -o sfml-app main.o Player.o Fruit.o -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

Player.o: Player.cpp Player.h
	g++ -std=c++17 -c Player.cpp

Fruit.o: Fruit.cpp Fruit.h
	g++ -std=c++17 -c Fruit.cpp

main.o : main.cpp Player.h Fruit.h
		g++ -std=c++17 -c main.cpp

clean:
	rm -rf *o sfml-app
