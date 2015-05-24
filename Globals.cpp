#include "Globals.h"

bool mouseOnSprite(const sf::RenderWindow & window, const sf::Sprite & sprite)
{
	//If any of these conditions is true, then the mouse is not on the sprite and false is returned.
	//Otherwise, all of these conditions are false and the function returns true.
	return !(sf::Mouse::getPosition(window).x < sprite.getPosition().x || sf::Mouse::getPosition(window).x > sprite.getPosition().x + sprite.getGlobalBounds().width || sf::Mouse::getPosition(window).y < sprite.getPosition().y || sf::Mouse::getPosition(window).y > sprite.getPosition().y + sprite.getGlobalBounds().height);
}

bool leftMouseButtonPressed(sf::RenderWindow & window, const sf::Event & sfEvent)
{
	return (sfEvent.type == sf::Event::MouseButtonPressed && sfEvent.mouseButton.button == sf::Mouse::Left);
}

bool leftMouseButtonReleased(sf::RenderWindow & window, const sf::Event & sfEvent)
{
	return (sfEvent.type == sf::Event::MouseButtonReleased && sfEvent.mouseButton.button == sf::Mouse::Left);
}

bool enterKeyPressed(sf::RenderWindow & window, const sf::Event & sfEvent)
{
	return (sfEvent.type == sf::Event::KeyPressed && sfEvent.key.code == sf::Keyboard::Return);
}

void setImage(const std::string & file, sf::Texture & texture, sf::Sprite & sprite, const sf::Vector2f & position)
{
	if (texture.loadFromFile(file))
	{
		sprite.setTexture(texture);
		sprite.setPosition(position);
	}
	else
		std::cerr << "Failed to open " << file << '\n';
}