#ifndef SLIDER_H
#define SLIDER_H

#include "Globals.h"

class Slider
{
private:
	sf::RenderWindow *window;
	sf::Texture socketTexture, sliderTexture;
	sf::Sprite socketSprite, sliderSprite;
	int amount;
	float ratio;
	bool pressed;
	bool active;
public:
	Slider();
	void init(const std::string & socketFilePath, const std::string & sliderFilePath, sf::RenderWindow & window, const sf::Vector2f & position = sf::Vector2f(0, 0), unsigned int amount = 0, bool active = true);
	void setActive(bool active);
	void setSlider(sf::Event & sfEvent);
	unsigned int getAmount() const;
	void display() const;
	~Slider();
};

#endif