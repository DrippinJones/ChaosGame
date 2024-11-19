// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;
	//vector<Vector2f> midpoint;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			

		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	
			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
				///fourth click
				///push back to points vector
				points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.
			
			int randVert = (rand() % vertices.size());
			
			/*int tempX = points.back().x;
			int tempY = points.back().y;

			int vertX = vertices.at(randVert).x;
			int vertY = vertices.at(randVert).y;*/

			int midPointX = (points.back().x + vertices.at(randVert).x) / 2;
			int midPointY = (points.back().y + vertices.at(randVert).y) / 2;


			points.push_back(Vector2f(midPointX, midPointY));
			
				
			//points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));

		}
	
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		for(int i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    
			int randNum = rand() % 3;

			rect.setFillColor(Color::Blue);

			/*if (randNum == 0) {
				rect.setFillColor(Color::Blue);
			}
			else if (randNum == 1)
			{
				rect.setFillColor(Color::Red);
			}
			else 
			{ 
				rect.setFillColor(Color::Green);
			}*/

		    window.draw(rect);
		}


		for (int i = 0; i < points.size(); i++)
		{
			RectangleShape rect(Vector2f(1, 1));
			rect.setPosition(Vector2f(points[i].x, points[i].y));
			
			int randNum = rand() % 3;

			rect.setFillColor(Color::Blue);

			/*if (randNum == 0) {
				rect.setFillColor(Color::Blue);
			}
			else if (randNum == 1)
			{
				rect.setFillColor(Color::Red);
			}
			else
			{
				rect.setFillColor(Color::Green);
			}*/

			window.draw(rect);
		}

		sf::Font font;
		if (!font.loadFromFile("comicSans.ttf"))
		{
			// error...
		}

		sf::Text text;

		// select the font
		text.setFont(font); // font is a sf::Font

		// set the string to display
		text.setString("Click three points for vertices and click again to start algorithm");

		// set the character size
		text.setCharacterSize(24); // in pixels, not points!

		// set the color
		text.setFillColor(sf::Color::Red);

		int randNum = rand() % 3;

		/*if (randNum == 0) {
			text.setFillColor(Color::Blue);
		}
		else if (randNum == 1)
		{
			text.setFillColor(Color::Red);
		}
		else
		{
			text.setFillColor(Color::Green);
		}*/

		// set the text style
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);


		// inside the main loop, between window.clear() and window.display()
		window.draw(text);



		window.display();
	}
}
