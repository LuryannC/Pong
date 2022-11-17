#ifndef PONGSFML_BAT_H
#define PONGSFML_BAT_H

#include <SFML/Graphics.hpp>


class Bat
{

 public:
  Bat(sf::RenderWindow& window);
  bool paddlesSprites();
  float bat_speed = 10.0f;
  sf::Sprite left_paddle;
  sf::Sprite right_paddle;


 private:
  sf::RenderWindow& window;
  sf::Texture right_paddle_texture;
  sf::Texture left_paddle_texture;

};

#endif // PONGSFML_BAT_H