all: sfml-app
	./sfml-app

sfml-app: main.o Player.o Fruit.o Vector2f.o
	g++ -std=c++17 -o sfml-app main.o Player.o Fruit.o Vector2f.o -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

Player.o: Player.cpp Player.h
	g++ -std=c++17 -c Player.cpp

Fruit.o: Fruit.cpp Fruit.h
	g++ -std=c++17 -c Fruit.cpp

Vector2f.o: Vector2f.cpp Vector2f.h
	g++ -std=c++17 -c Vector2f.cpp

main.o : main.cpp Player.h Fruit.h Vector2f.h
		g++ -std=c++17 -c main.cpp

clean:
	rm -rf *o sfml-app
