#include "Button.h"

Button::Button()
{
}

void Button::init(const std::string & file, const std::string & hoverFile, sf::RenderWindow & w, const sf::Vector2f & pos)
{
	hovered = false;
	pressed = false;
	active = true;
	setImage(file, texture, sprite, pos);
	setImage(hoverFile, hoverTexture, hoverSprite, pos);
	window = &w;
}

void Button::setActive(bool act)
{
	active = act;
}

bool Button::isClicked(const sf::Event & sfEvent)
{
	if (active)
	{
		if (!mouseOnSprite(*window, sprite))
		{
			hovered = false;
			pressed = pressed ? !leftMouseButtonReleased(*window, sfEvent) : pressed;
			return false;
		}
		else
		{
			hovered = true;
			if (enterKeyPressed(*window, sfEvent))
				return true;
			pressed = !pressed ? leftMouseButtonPressed(*window, sfEvent) : pressed;
			if (pressed)
				return !(pressed = !leftMouseButtonReleased(*window, sfEvent));
		}
	}
	return false;
}

void Button::display() const
{
	if (hovered)
		window->draw(hoverSprite);
	else
		window->draw(sprite);
}

Button::~Button()
{
}