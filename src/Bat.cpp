#include "Bat.h"
#include "Game.h"
#include <iostream>

Bat::Bat(sf::RenderWindow& game_window) : window(game_window){
}

bool Bat::paddlesSprites()
{
  // Left Paddle
  if (!left_paddle_texture.loadFromFile("Data/Images/fishTile_099.png")){
    std::cout << "Left paddle did not load \n";
  }
  left_paddle_texture.setSmooth(true);
  left_paddle.setTexture(left_paddle_texture);
  left_paddle.setPosition(16,200);
  left_paddle.setScale(1.3f, 1.3f);

  // Right Paddle
  if (!right_paddle_texture.loadFromFile("Data/Images/fishTile_099.png")){
    std::cout << "Right paddle did not load \n";
  }
  right_paddle_texture.setSmooth(true);
  right_paddle.setTexture(right_paddle_texture);
  right_paddle.setPosition(1000,200);
  right_paddle.setScale(1.3f, 1.3f);


  return true;
}

void Game::movePaddles()
{
  // Keys that calls functions to move up and down
  if (current_state == multiplayer){
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        Bat->left_paddle.move(0, -Bat->bat_speed);
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        Bat->left_paddle.move(0, Bat->bat_speed);
    }
  }else
  {
      // Ai Decision Easy
      if (Ai->curren_difficulty == Ai->easy)
      {
        if (Ai->number_difficulty < 4)
        {
          if (
            Bat->left_paddle.getPosition().y <
            Ball[0]->getY() - Bat->left_paddle.getLocalBounds().height)
          {
            Bat->left_paddle.move(0, Bat->bat_speed);
          }
          else if (
            Bat->left_paddle.getPosition().y +
              Ball[0]->ball.getGlobalBounds().height >
            Ball[0]->getY() + Bat->left_paddle.getLocalBounds().height)
          {
            Bat->left_paddle.move(0, -Bat->bat_speed);
          }
        }
      }
      // Medium
      else if (Ai->curren_difficulty == Ai->medium)
      {
        if (Ai->number_difficulty > 5)
        {
          if (
            Bat->left_paddle.getPosition().y + 5 <
            Ball[0]->getY() - Bat->left_paddle.getLocalBounds().height)
          {
            Bat->left_paddle.move(0, Bat->bat_speed * Ball[0]->ball_speed);
          }
          else if (
            Bat->left_paddle.getPosition().y +
              Ball[0]->ball.getGlobalBounds().height + 5 >
            Ball[0]->getY() + Bat->left_paddle.getLocalBounds().height)
          {
            Bat->left_paddle.move(0, -Bat->bat_speed * Ball[0]->ball_speed);
          }
        }
      }
      // Hard
      else if (Ai->curren_difficulty == Ai->hard)
      {
        if (Ai->number_difficulty >= 3)
        {
          if (
            Bat->left_paddle.getPosition().y + 10 <
            Ball[0]->getY() - Bat->left_paddle.getLocalBounds().height)
          {
            Bat->left_paddle.move(0, Bat->bat_speed * Ball[0]->ball_speed);
          }
          else if (
            Bat->left_paddle.getPosition().y +
              Ball[0]->ball.getGlobalBounds().height + 10 >
            Ball[0]->getY() + Bat->left_paddle.getLocalBounds().height)
          {
            Bat->left_paddle.move(0, -Bat->bat_speed * Ball[0]->ball_speed);
          }
        }
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      Bat->right_paddle.move(0, -Bat->bat_speed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      Bat->right_paddle.move(0, Bat->bat_speed);
    }

  // if paddle reach the top edge, reset its position to 0.1f down
  if (Bat->left_paddle.getPosition().y <= 0){
    Bat->left_paddle.move(0, Bat->bat_speed);
  }
  // if paddle reach the bottom edge, reset its position to 0.1f above
  else if(Bat->left_paddle.getPosition().y >= (window.getSize().y - Bat->left_paddle.getGlobalBounds().height)){
    Bat->left_paddle.move(0, -Bat->bat_speed);
  }
  if (Bat->right_paddle.getPosition().y <= 0){
    Bat->right_paddle.move(0, Bat->bat_speed);
  }
  else if(Bat->right_paddle.getPosition().y >= (window.getSize().y - Bat->right_paddle.getGlobalBounds().height)){
    Bat->right_paddle.move(0, -Bat->bat_speed);
  }
}
