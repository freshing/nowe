#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main()
{
	sf::RenderWindow okno;

	okno.create(sf::VideoMode(640, 480, 32), "Programik");

	sf::Texture tekstura;
	tekstura.loadFromFile("..\\images\\sfml-logo-small.png");


	sf::Image obrazek;
	obrazek.loadFromFile("..\\images\\kwadrat.png");
	obrazek.saveToFile("..\\images\\obrazek.png");


	//sf::Uint8* pixels = new sf::Uint8[200 * 200 * 4]; // * 4 poniewa¿ piskele sk³adaj¹ siê z 4 sk³adników (RGBA)
	//tekstura.update(pixels);

	sf::Sprite sprajt;
	sprajt.setTexture(tekstura);

	//okno.clear(sf::Color::Red);

	sf::CircleShape kolo(100);
	kolo.setFillColor(sf::Color::Red);


	while (okno.isOpen())
	{
		
		sf::Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				okno.close();
			if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::Escape)
				okno.close();
			if (zdarzenie.mouseButton.button == sf::Mouse::Middle)
				okno.close();

			if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::F1)
			{
				sf::Image zrzutEkranu = okno.capture();
				zrzutEkranu.saveToFile("..\\images\\ss.png");
			}

		}
		//okno.clear(sf::Color::Black);
		sprajt.setPosition(sf::Vector2f(200,200));
		kolo.setPosition(50, 50);
		okno.draw(sprajt);
		okno.draw(kolo);
		okno.display();
	}
	return 0;
}