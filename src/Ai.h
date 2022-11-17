#ifndef PONGSFML_AI_H
#define PONGSFML_AI_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Vector.h"

class Ai
{
 public:
  Ai(sf::RenderWindow& window);
  ~Ai();
  int randomNum();
  int number_difficulty;

  enum Difficulty{
    easy,
    medium,
    hard
  };
  int curren_difficulty = hard;

 private:
  sf::RenderWindow& window;

};

#endif // PONGSFML_AI_H
