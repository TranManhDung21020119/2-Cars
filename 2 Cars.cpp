// 2 Cars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <sstream>
#include <string>

sf::Texture _roadbackground() {
	sf::Texture road_background;
	road_background.loadFromFile("roadbackground.png");
	return road_background;
}

sf::Texture _clientbackground() {
	sf::Texture client_background;
	client_background.loadFromFile("clientbackground.png");
	return client_background;
}

sf::Texture _redroad() {
	sf::Texture red_road;
	red_road.loadFromFile("redroad.png");
	return red_road;
}

sf::Texture _blueroad() {
	sf::Texture blue_road;
	blue_road.loadFromFile("blueroad.png");
	return blue_road;
}

sf::Texture _redcar() {
	sf::Texture red_car;
	red_car.loadFromFile("redcar.png");
	return red_car;
}

sf::Texture _bluecar() {
	sf::Texture blue_car;
	blue_car.loadFromFile("bluecar.png");
	return blue_car;
}

sf::Texture _redcircle() {
	sf::Texture red_circle;
	red_circle.loadFromFile("redcircle.png");
	return red_circle;
}

sf::Texture _bluecircle() {
	sf::Texture blue_circle;
	blue_circle.loadFromFile("bluecircle.png");
	return blue_circle;
}

sf::Texture _redsquare() {
	sf::Texture red_square;
	red_square.loadFromFile("redsquare.png");
	return red_square;
}

sf::Texture _bluesquare() {
	sf::Texture blue_square;
	blue_square.loadFromFile("bluesquare.png");
	return blue_square;
}

int score_now;
bool inGame = 1, isPlaying = 0;

void play()
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 900), "2 Cars", sf::Style::Titlebar | sf::Style::Close);

	sf::Event event;

	sf::Font font;
	font.loadFromFile("ARCADE_R.TTF");

	sf::Texture RoadBackground = _roadbackground();
	sf::Sprite Road_Background(RoadBackground);

	int score = 0;

	sf::Text Score;

	Score.setPosition(10, 10);
	Score.setOrigin(0, 0);
	Score.setFont(font);
	Score.setCharacterSize(20);
	Score.setFillColor(sf::Color::Magenta);

	double Speed = 200.f;

	sf::Texture RedRoad = _redroad();
	sf::Sprite Red_Road[8];
	for (int i = 0; i < 8; i++) {
		Red_Road[i].setTexture(RedRoad);
		Red_Road[i].setOrigin(20, 40);
		Red_Road[i].setPosition(200, -190 + (7 - i) * 150);
	}

	sf::Texture BlueRoad = _blueroad();
	sf::Sprite Blue_Road[8];
	for (int i = 0; i < 8; i++) {
		Blue_Road[i].setTexture(BlueRoad);
		Blue_Road[i].setOrigin(20, 40);
		Blue_Road[i].setPosition(600, -190 + (7 - i) * 150);
	}

	sf::Texture RedCar = _redcar();
	sf::Sprite Red_Car(RedCar);
	Red_Car.setOrigin(30, 40);
	Red_Car.setPosition(300, 750);

	sf::Texture BlueCar = _bluecar();
	sf::Sprite Blue_Car(BlueCar);
	Blue_Car.setOrigin(30, 40);
	Blue_Car.setPosition(500, 750);

	sf::Texture RedCircle = _redcircle();
	sf::Sprite Red_Circle(RedCircle);
	Red_Circle.setOrigin(40, 40);

	sf::Texture BlueCircle = _bluecircle();
	sf::Sprite Blue_Circle(BlueCircle);
	Blue_Circle.setOrigin(40, 40);

	sf::Texture RedSquare = _redsquare();
	sf::Sprite Red_Square(RedSquare);
	Red_Square.setOrigin(40, 40);

	sf::Texture BlueSquare = _bluesquare();
	sf::Sprite Blue_Square(BlueSquare);
	Blue_Square.setOrigin(40, 40);

	sf::Sprite Red_Object[4];
	bool Rcircle[4];
	for (int i = 0; i < 4; i++) {
		int k = rand();
		if (k % 2 == 0) {
			Red_Object[i] = Red_Circle;
			Rcircle[i] = 1;
		}
		else {
			Red_Object[i] = Red_Square;
			Rcircle[i] = 0;
		}

		k = rand();
		Red_Object[i].setPosition(300 - (k % 3) * 200, 0 - i * 225);
	}

	sf::Sprite Blue_Object[4];
	bool Bcircle[4];
	for (int i = 0; i < 4; i++) {
		int k = rand();
		if (k % 2 == 0) {
			Blue_Object[i] = Blue_Circle;
			Bcircle[i] = 1;
		}
		else {
			Blue_Object[i] = Blue_Square;
			Bcircle[i] = 0;
		}

		k = rand();
		Blue_Object[i].setPosition(500 + (k % 3) * 200, 0 - i * 225);
	}
	int red_last_object = 0, blue_last_object = 0;

	sf::Clock clock;
	double deltaTime = 0.f;

	bool Red_Status = 1, Blue_Status = 0;

	while (window.isOpen()) {
		std::stringstream ss;
		deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				inGame = 0;
				return;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (Red_Status) {
				Red_Status = 0;
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (!Red_Status) {
				Red_Status = 1;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
			if (Blue_Status) {
				Blue_Status = 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
			if (!Blue_Status) {
				Blue_Status = 1;
			}
		}

		if (Red_Status) {
			if (Red_Car.getPosition().x < 300) {
				Red_Car.move(deltaTime * Speed * 5, 0);
			}

			if (Red_Car.getPosition().x >= 300) {
				Red_Car.setPosition(300, 750);
			}
		}

		if (!Red_Status) {
			if (Red_Car.getPosition().x > 100) {
				Red_Car.move(-deltaTime * Speed * 5, 0);
			}

			if (Red_Car.getPosition().x <= 100) {
				Red_Car.setPosition(100, 750);
			}
		}

		if (Blue_Status) {
			if (Blue_Car.getPosition().x < 700) {
				Blue_Car.move(deltaTime * Speed * 5, 0);
			}

			if (Blue_Car.getPosition().x >= 700) {
				Blue_Car.setPosition(700, 750);
			}
		}

		if (!Blue_Status) {
			if (Blue_Car.getPosition().x > 500) {
				Blue_Car.move(-deltaTime * Speed * 5, 0);
			}

			if (Blue_Car.getPosition().x <= 500) {
				Blue_Car.setPosition(500, 750);
			}
		}

		if (Red_Object[red_last_object].getPosition().y > 670) {
			if (Red_Object[red_last_object].getPosition().x != -100) {
				if ((abs(Red_Object[red_last_object].getPosition().y - Red_Car.getPosition().y) < 80) &&
					(abs(Red_Object[red_last_object].getPosition().x - Red_Car.getPosition().x) < 60)) {
					if (Rcircle[red_last_object]) {
						Red_Object[red_last_object].setPosition(-100, Red_Object[red_last_object].getPosition().y);
						score++;
					}
					else {
						window.close();
					}
				}
			}
		}

		if (Blue_Object[blue_last_object].getPosition().y > 670) {
			if (Blue_Object[blue_last_object].getPosition().x != 900) {
				if ((abs(Blue_Object[blue_last_object].getPosition().y - Blue_Car.getPosition().y) < 80) &&
					(abs(Blue_Object[blue_last_object].getPosition().x - Blue_Car.getPosition().x) < 60)) {
					if (Bcircle[blue_last_object]) {
						Blue_Object[blue_last_object].setPosition(900, Blue_Object[blue_last_object].getPosition().y);
						score++;
					}
					else {
						window.close();
					}
				}
			}
		}

		for (int i = 0; i < 8; i++) {
			Blue_Road[i].move(0, deltaTime * 2 * Speed);
			if (Blue_Road[i].getPosition().y > 940) {
				int j = (i + 7) % 8;
				Blue_Road[i].setPosition(600, Blue_Road[j].getPosition().y - 150);

				Speed += 1;
			}

			Red_Road[i].move(0, deltaTime * 2 * Speed);
			if (Red_Road[i].getPosition().y > 940) {
				int j = (i + 7) % 8;
				Red_Road[i].setPosition(200, Red_Road[j].getPosition().y - 150);
			}
		}

		for (int i = 0; i < 4; i++) {
			Red_Object[i].move(0, deltaTime * 2 * Speed);
			if (Red_Object[i].getPosition().y > 750) {
				red_last_object = (red_last_object + 1) % 4;
			}

			if (Red_Object[i].getPosition().y > 900) {
				if (Rcircle[i] && Red_Object[i].getPosition().x != -100) {
					window.close();
				}
				int j = (i + 3) % 4;
				int k = rand();
				if (k % 2 == 0) {
					Red_Object[i] = Red_Circle;
					Rcircle[i] = 1;
				}
				else {
					Red_Object[i] = Red_Square;
					Rcircle[i] = 0;
				}

				k = rand();
				Red_Object[i].setPosition(300 - (k % 3) * 200, Red_Object[j].getPosition().y - 225);

				red_last_object = (red_last_object + 1) % 4;
			}

			Blue_Object[i].move(0, deltaTime * 2 * Speed);
			if (Blue_Object[i].getPosition().y > 750) {
				blue_last_object = (blue_last_object + 1) % 4;
			}

			if (Blue_Object[i].getPosition().y > 900) {
				if (Bcircle[i] && Blue_Object[i].getPosition().x != 900) {
					window.close();
				}
				int j = (i + 3) % 4;
				int k = rand();
				if (k % 2 == 0) {
					Blue_Object[i] = Blue_Circle;
					Bcircle[i] = 1;
				}
				else {
					Blue_Object[i] = Blue_Square;
					Bcircle[i] = 0;
				}

				k = rand();
				Blue_Object[i].setPosition(500 + (k % 3) * 200, Blue_Object[j].getPosition().y - 225);
			}
		}

		ss << score;
		Score.setString(ss.str().c_str());

		score_now = score;

		window.draw(Road_Background);

		for (int i = 0; i < 8; i++) {
			window.draw(Blue_Road[i]);
			window.draw(Red_Road[i]);
		}

		for (int i = 0; i < 4; i++) {
			window.draw(Red_Object[i]);
			window.draw(Blue_Object[i]);
		}

		window.draw(Red_Car);

		window.draw(Blue_Car);

		window.draw(Score);

		window.display();
	}
}

void client() {
	sf::RenderWindow window(sf::VideoMode(700, 400), "2 Cars Client", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;

	sf::Font font;
	font.loadFromFile("ARCADE_R.TTF");

	sf::Text text, Score;
	text.setFillColor(sf::Color::Magenta);
	text.setFont(font);
	text.setCharacterSize(15);
	text.setString("Press Y to play, N to close window");
	text.setPosition(100, 200);

	Score.setFillColor(sf::Color::Magenta);
	Score.setFont(font);
	Score.setCharacterSize(20);

	sf::Texture ClientBackground = _clientbackground();
	sf::Sprite Client_Background(ClientBackground);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				inGame = 0;
				break;
			}
		}

		std::stringstream ss;
		ss << score_now;
		Score.setString(ss.str().c_str());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
			isPlaying = 1;
			play();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
			inGame = 0;
			window.close();
		}

		window.draw(Client_Background);

		window.draw(text);

		window.draw(Score);

		window.display();
	}
}

int main() {
	while (inGame) {
		if (!isPlaying) {
			client();
		}
		else {
			play();
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
