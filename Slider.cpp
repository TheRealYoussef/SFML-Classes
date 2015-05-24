#include "Slider.h"

Slider::Slider()
{
}

void Slider::init(const std::string & socketFilePath, const std::string & sliderFilePath, sf::RenderWindow & w, const sf::Vector2f & pos, unsigned int n)
{
	active = true;
	pressed = false;
	window = &w;
	amount = n;
	setImage(socketFilePath, socketTexture, socketSprite, pos);
	//Couldn't use setImage() because the position is calculated after the sprite has been set
	if (sliderTexture.loadFromFile(sliderFilePath))
	{
		sliderSprite.setTexture(sliderTexture);
		sliderSprite.setPosition(pos + sf::Vector2f(-sliderSprite.getLocalBounds().width / 2.f + (float)n * (ratio = (float)(socketSprite.getLocalBounds().width) / 100.f), -(sliderSprite.getLocalBounds().height - socketSprite.getLocalBounds().height) / 2.f));
	}
	else
		std::cerr << "Failed to open " << sliderFilePath << '\n';
}

void Slider::setActive(bool act)
{
	active = act;
}

void Slider::setSlider(sf::Event & sfEvent)
{
	if (active)
	{
		//Deal with drag and drop of slider
		if (pressed)
		{
			if (pressed = !leftMouseButtonReleased(*window, sfEvent))
			{
				amount = (sf::Mouse::getPosition(*window).x - socketSprite.getPosition().x) / ratio;
				amount = (amount < 0) ? 0 : (amount > 100) ? 100 : amount;
				sliderSprite.setPosition(socketSprite.getPosition() + sf::Vector2f(-sliderSprite.getLocalBounds().width / 2 + (float)amount * ratio, -(sliderSprite.getLocalBounds().height - socketSprite.getLocalBounds().height) / 2.f));
			}
		}
		else if (mouseOnSprite(*window, sliderSprite))
			pressed = leftMouseButtonPressed(*window, sfEvent);
		//Deal with pressing on the socket
		else if (mouseOnSprite(*window, socketSprite))
		{
			if (leftMouseButtonPressed(*window, sfEvent))
			{
				amount = (sf::Mouse::getPosition(*window).x - socketSprite.getPosition().x) / ratio;
				amount = (amount < 0) ? 0 : (amount > 100) ? 100 : amount;
				sliderSprite.setPosition(socketSprite.getPosition() + sf::Vector2f(-sliderSprite.getLocalBounds().width / 2 + (float)amount * ratio, -(sliderSprite.getLocalBounds().height - socketSprite.getLocalBounds().height) / 2.f));
			}
		}
	}
}

unsigned int Slider::getAmount() const
{
	return amount;
}

void Slider::display() const
{
	window->draw(socketSprite);
	window->draw(sliderSprite);
}

Slider::~Slider()
{
}