#include "Ball.h"
#include "Game.h"
#include <iostream>

Ball::Ball(sf::RenderWindow& game_window) : window(game_window){

}

bool Ball::ballSprite()
{
  // Ball
  if (!ball_texture.loadFromFile("Data/Images/fishTile_101.png")){
    std::cout << "Ball did not load \n";
    return false;
  }

  ball_texture.setSmooth(true);
  ball.setTexture(ball_texture);
  ball.setPosition(window.getSize().x/2, 320);
  ball.setScale(0.7f, 0.7f);

  return true;
}

float Ball::getX()
{
  ball_x = ball.getPosition().x;
  return ball_x;
}
float Ball::getY()
{
  ball_y = ball.getPosition().y;
  return ball_y;
}


void Game::moveBall(float dt)
{
  // Check if ball intersects with Right or Left Paddle
  for (int i = 0; i < n_balls; ++i)
  {
    Ball[i]->ball.move( Vector[i]->x * Ball[i]->ball_speed * dt, Vector[i]->y * Ball[i]->ball_speed * dt);
  if (Vector[i]->x < 0)
  {
    if(Ball[i]->ball.getPosition().x + Ball[i]->ball.getGlobalBounds().width > Bat->left_paddle.getPosition().x &&
        Ball[i]->ball.getPosition().x < Bat->left_paddle.getPosition().x + Bat->left_paddle.getGlobalBounds().width &&
        Ball[i]->ball.getPosition().y < Bat->left_paddle.getPosition().y + Bat->left_paddle.getGlobalBounds().height - 10 &&
        Ball[i]->ball.getPosition().y + Ball[i]->ball.getGlobalBounds().height - 10 > Bat->left_paddle.getPosition().y)
    {
      Ball[i]->ball.setTextureRect(sf::IntRect(0, 0, Ball[i]->ball.getLocalBounds().width, Ball[i]->ball.getLocalBounds().height));
      Vector[i]->x = -Vector[i]->x;
    }
  }
  else
  {
    if(Ball[i]->ball.getPosition().x + Ball[i]->ball.getGlobalBounds().width > Bat->right_paddle.getPosition().x &&
        Ball[i]->ball.getPosition().x < Bat->right_paddle.getPosition().x + Bat->right_paddle.getGlobalBounds().width &&
        Ball[i]->ball.getPosition().y < Bat->right_paddle.getPosition().y + Bat->right_paddle.getGlobalBounds().height - 10 &&
        Ball[i]->ball.getPosition().y + Ball[i]->ball.getGlobalBounds().height - 10 > Bat->right_paddle.getPosition().y)
    {
      Ball[i]->ball.setTextureRect(sf::IntRect(Ball[i]->ball.getLocalBounds().width, 0, -Ball[i]->ball.getLocalBounds().width, Ball[i]->ball.getLocalBounds().height));
      Vector[i]->x = -Vector[i]->x;
    }
  }
  // Walls collisions
  if (Ball[i]->ball.getPosition().y + Ball[i]->ball.getGlobalBounds().height + 5 > window.getSize().y){
    Vector[i]->y = -Vector[i]->y;
  }
  else if (Ball[i]->ball.getPosition().y < 0){
    Vector[i]->y = -Vector[i]->y;
  }
  // Ball Reset
  // Right
  else if (Ball[i]->ball.getPosition().x + Ball[i]->ball.getGlobalBounds().width > window.getSize().x + Ball[i]->ball.getGlobalBounds().width){
    Ball[i]->ball.setPosition(window.getSize().x/2,window.getSize().y/2);
    Ball[i]->ball.setTextureRect(sf::IntRect(Ball[i]->ball.getLocalBounds().width, 0, -Ball[i]->ball.getLocalBounds().width, Ball[i]->ball.getLocalBounds().height));
    Vector[i]->x = -Vector[i]->x;
    Vector[i]->y = -Vector[i]->y;
    Ai->randomNum();
    if (current_state == multiplayer){
      if (add_ball){
          addScoreRight();
      }
      else {
        if (Ball[i] == Ball[0]){
          addScoreRight();
        }
      }
    }
    else{
      if (Ball[i] == Ball[0]){
          addScoreRight();
      }
    }
  }
  // Left
  else if (Ball[i]->ball.getPosition().x < 0 - Ball[i]->ball.getGlobalBounds().width){
    Ball[i]->ball.setPosition(window.getSize().x/2,window.getSize().y/2);
    Ball[i]->ball.setTextureRect(sf::IntRect(0, 0, Ball[i]->ball.getLocalBounds().width, Ball[i]->ball.getLocalBounds().height));
    Vector[i]->x = -Vector[i]->x;
    Vector[i]->y = -Vector[i]->y;
    Ai->randomNum();
    if (current_state == multiplayer){
      if (add_ball){
        addScoreLeft();
      }
      else {
        if (Ball[i] == Ball[0]){
          addScoreLeft();
        }
      }
    }
    else{
      if (Ball[i] == Ball[0]){
        addScoreLeft();
      }
    }
  }
  }
}


