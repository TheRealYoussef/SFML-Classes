#ifndef BUTTON_H
#define BUTTON_H

#include "Globals.h"

class Button
{
private:
	sf::RenderWindow * window;
	sf::Texture texture, hoverTexture;
	sf::Sprite sprite, hoverSprite;
	bool hovered;
	bool pressed;
	bool active;
public:
	Button();
	void init(const std::string & imageFilePath, const std::string & hoverImageFilePath, sf::RenderWindow & window, const sf::Vector2f & position = sf::Vector2f(0, 0));
	void setActive(bool active);
	bool isClicked(const sf::Event & sfEvent);
	void display() const;
	~Button();
};

#endif