#include "Ai.h"
#include <iostream>

Ai::Ai(sf::RenderWindow& game_window) : window(game_window)
{
  srand (time(NULL));
  randomNum();
}

Ai::~Ai()
{
}

int Ai::randomNum()
{
  if (curren_difficulty == easy){
    number_difficulty = rand() % 11 + 1;
    return number_difficulty;
  }
  else if (curren_difficulty == medium){
    number_difficulty = rand() % 10 + 1;
    return number_difficulty;
  }
  else {
    number_difficulty = rand() % 8 + 1;
    return number_difficulty;
  }
}

