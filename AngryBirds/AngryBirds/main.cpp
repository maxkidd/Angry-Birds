#include <SFML\Window\Event.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\ConvexShape.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <Windows.h>


int main()
{
#ifdef NDEBUG // If release mode, hide console
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);
#endif

	// Setup window
	sf::RenderWindow window;
	window.create(sf::VideoMode(600, 550), "Angry Birds!");

	// Create a polygon
	sf::ConvexShape sfPolygon(3);
	sfPolygon.setOutlineColor(sf::Color::Red);
	sfPolygon.setOutlineThickness(1);
	sfPolygon.setPoint(0, sf::Vector2f(100.0f, 100.0f));
	sfPolygon.setPoint(1, sf::Vector2f(150.0f, 150.0f));
	sfPolygon.setPoint(2, sf::Vector2f(50.0f, 150.0f));

	// Create a circle shape
	sf::CircleShape sfCircle;
	sfCircle = sf::CircleShape(100.0f, 30);
	sfCircle.setPosition(300.0f, 300.0f);

	sf::Event event;
	while (window.isOpen()) // While still in the window
	{
		window.clear(); // Clear render window

		while (window.pollEvent(event)) // Simple version of getting events from windows
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
				;// input.OnKeyDown(event.key.code);
			else if (event.type == sf::Event::KeyReleased)
				;// input.OnKeyUp(event.key.code);
		}


		window.draw(sfPolygon); // Draw polygon onto render window ready to be displayed
		window.draw(sfCircle); // Draw circle

		window.display(); // Display render window
	}

	return 0; // Program exits with no errors
}