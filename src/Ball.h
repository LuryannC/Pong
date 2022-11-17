//
// Created by luria on 05/12/2021.
//

#ifndef PONGSFML_BALL_H
#define PONGSFML_BALL_H

#include "Bat.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <list>

class Ball
{
 public:
  Ball(sf::RenderWindow& window);
  bool ballSprite();
  float getX();
  float getY();

  float ball_x;
  float ball_y;

  sf::Sprite ball;
  sf::Texture ball_texture;
  float ball_speed = 1.0f;

 private:
  sf::RenderWindow& window;

};

#endif // PONGSFML_BALL_H
