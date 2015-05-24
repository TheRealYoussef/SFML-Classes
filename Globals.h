#ifndef GLOBALS_H
#define GLOBALS_H

#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>

bool mouseOnSprite(const sf::RenderWindow & window, const sf::Sprite & sprite);

bool leftMouseButtonPressed(sf::RenderWindow & window, const sf::Event & sfEvent);

bool leftMouseButtonReleased(sf::RenderWindow & window, const sf::Event & sfEvent);

bool enterKeyPressed(sf::RenderWindow & window, const sf::Event & sfEvent);

void setImage(const std::string & file, sf::Texture & texture, sf::Sprite & sprite, const sf::Vector2f & position);

#endif