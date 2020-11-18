all: sfml-app
	./sfml-app

sfml-app: main.o Vector2.o Game.o World.o Player.o Fruit.o Textbox.o
	g++ -std=c++17 -o sfml-app main.o Player.o  Vector2.o World.o Game.o Fruit.o Textbox.o -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

Player.o: Player.cpp Player.h
	g++ -std=c++17 -c Player.cpp

Game.o: Game.cpp Game.h
	g++ -std=c++17 -c Game.cpp

World.o: World.cpp World.h
	g++ -std=c++17 -c World.cpp

Fruit.o: Fruit.cpp Fruit.h
	g++ -std=c++17 -c Fruit.cpp

Vector2.o: Vector2.cpp Vector2.h
	g++ -std=c++17 -c Vector2.cpp

Textbox.o : Textbox.cpp Textbox.h
	g++ -std=c++17 -c Textbox.cpp




main.o : main.cpp Player.h Fruit.h Vector2.h World.h Game.h Textbox.h
		g++ -std=c++17 -c main.cpp

clean:
	rm -rf *o sfml-app
