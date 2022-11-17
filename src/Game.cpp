
#include "Game.h"
#include <iostream>
#include <vector>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));

  // Initialise the Vector
  for (int i = 0; i < n_balls; ++i)
  {
    Vector[i] = new class Vector(40.0f, 20.0f);
    Ball[i] = new class Ball(window);
  }
  Bat = new class Bat(window);
  RenderHelper = new class RenderHelper(window);
  Ai = new class Ai(window);




}

Game::~Game()
{
  for (int i = 0; i < n_balls; ++i){
    delete Vector[i];
    delete Ball[i];
  }
  delete Bat;
  delete RenderHelper;
  delete Ai;
}

bool Game::init()
{
  Bat->paddlesSprites();
  Ball[0]->ballSprite();
  Ball[1]->ballSprite();
  RenderHelper->renderHud();
}

void Game::update(float dt)
{

    if (in_game){
      moveBall(dt);
      movePaddles();
      if (current_state == singleplayer){
        Ai->randomNum();
      }
      if (RenderHelper->current_score_left == 5 || RenderHelper->current_score_right == 5){
        in_game = false;
        current_state = game_over;
        diff_window = 1;
      }
    }
}

void Game::render()
{
  window.draw(RenderHelper->background);


  switch (current_state)
  {
    case in_menu:
      window.draw(RenderHelper->game_title);
      window.draw(RenderHelper->play_text);
      window.draw(RenderHelper->multiplayer_text);
      window.draw(RenderHelper->exit_game);
      break;
    case difficulty:
      window.draw(RenderHelper->game_title);
      window.draw(RenderHelper->difficulty_text);
      window.draw(RenderHelper->diff_selection);
      window.draw(RenderHelper->return_text);
      break;
    case singleplayer:
      window.draw(RenderHelper->rectangle);
      window.draw(RenderHelper->score_left);
      window.draw(RenderHelper->score_right);
      window.draw(RenderHelper->exit_key);
      window.draw(Ball[0]->ball);
      window.draw(Bat->left_paddle);
      window.draw(Bat->right_paddle);
      break;
    case multiplayer:
      window.draw(RenderHelper->rectangle);
      window.draw(RenderHelper->score_left);
      window.draw(RenderHelper->score_right);
      window.draw(RenderHelper->exit_key);
      window.draw(RenderHelper->extra_ball);
      window.draw(Ball[0]->ball);
      if (add_ball){
          window.draw(Ball[1]->ball);
      }
      window.draw(Bat->left_paddle);
      window.draw(Bat->right_paddle);
      break;
    case game_over:
      window.draw(RenderHelper->game_over);
      RenderHelper->exit_key.setPosition(window.getSize().x / 2 - 100 , 610);
      RenderHelper->exit_key.setCharacterSize(50);
      window.draw(RenderHelper->exit_key);
      RenderHelper->score_left.setPosition(window.getSize().x / 3, window.getSize().y / 2);
      RenderHelper->score_right.setPosition(window.getSize().x / 1.63f, window.getSize().y / 2);
      window.draw(RenderHelper->score_left);
      window.draw(RenderHelper->score_right);
      break;
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

}


void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Space){
    if (!add_ball){
      Ball[1]->ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
      add_ball = true;
    }
  }
  if (event.key.code == sf::Keyboard::Up){
    if (current_state == in_menu){
      play_selected--;
      if (play_selected > 3)
      {
        play_selected = 3;
      }
    }
    else if (current_state == difficulty){
      diff_window--;
      if (diff_window < 0)
      {
        diff_window = 0;
      }
    }
  }
  else if (event.key.code == sf::Keyboard::Down){
    if (current_state == in_menu){
      play_selected++;
      if (play_selected < 1)
      {
        play_selected = 1;
      }
    }
    else if (current_state == difficulty){
      diff_window++;
      if (diff_window > 1)
      {
        diff_window = 1;
      }
    }
  }
  else if (current_state == difficulty)
  {
    if (event.key.code == sf::Keyboard::Right)
    {
      diff_selected++;
      if (diff_selected > 3)
      {
        diff_selected = 3;
      }
    }
    else if (event.key.code == sf::Keyboard::Left)
    {
      diff_selected--;
      if (diff_selected < 1)
      {
        diff_selected = 1;
      }
    }
  }

  // Change colours and outline when selected

  if (play_selected == SingleOp)
  {
    RenderHelper->play_text.setFillColor(sf::Color::Red);
    RenderHelper->play_text.setOutlineThickness(0);
    RenderHelper->multiplayer_text.setFillColor(sf::Color::White);
    RenderHelper->multiplayer_text.setOutlineThickness(2.0f);
    RenderHelper->exit_game.setFillColor(sf::Color::White);
    RenderHelper->exit_game.setOutlineThickness(2.0f);
  }
  else if (play_selected == MultipOp)
  {
    RenderHelper->play_text.setFillColor(sf::Color::White);
    RenderHelper->play_text.setOutlineThickness(2.0f);
    RenderHelper->multiplayer_text.setFillColor(sf::Color::Red);
    RenderHelper->multiplayer_text.setOutlineThickness(0);
    RenderHelper->exit_game.setFillColor(sf::Color::White);
    RenderHelper->exit_game.setOutlineThickness(2.0f);
  }
  else if (play_selected == ExitOp)
  {
    RenderHelper->play_text.setFillColor(sf::Color::White);
    RenderHelper->play_text.setOutlineThickness(2.0f);
    RenderHelper->multiplayer_text.setFillColor(sf::Color::White);
    RenderHelper->multiplayer_text.setOutlineThickness(2.0f);
    RenderHelper->exit_game.setFillColor(sf::Color::Red);
    RenderHelper->exit_game.setOutlineThickness(0);
  }

  if (diff_selected == easy)
  {
    RenderHelper->diff_selection.setString("Easy");
    RenderHelper->diff_selection.setPosition(window.getSize().x / 2 - 50, 520);
  }
  else if (diff_selected == medium)
  {
    RenderHelper->diff_selection.setString("Medium");
    RenderHelper->diff_selection.setPosition(window.getSize().x / 2 - 105, 520);
  }
  else if (diff_selected == hard)
  {
    RenderHelper->diff_selection.setString("Hard");
    RenderHelper->diff_selection.setPosition(window.getSize().x / 2 - 57, 520);
  }

  if (diff_window == 0)
  {
    RenderHelper->diff_selection.setFillColor(sf::Color::Red);
    RenderHelper->diff_selection.setOutlineThickness(0);
    RenderHelper->return_text.setFillColor(sf::Color::White);
    RenderHelper->return_text.setOutlineThickness(2.0f);
  }
  else if (diff_window == 1)
  {
    RenderHelper->diff_selection.setFillColor(sf::Color::White);
    RenderHelper->diff_selection.setOutlineThickness(2.0f);
    RenderHelper->return_text.setFillColor(sf::Color::Red);
    RenderHelper->return_text.setOutlineThickness(0);
  }
  if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected == SingleOp)
    {
      current_state = difficulty;
    }
    else if (play_selected == MultipOp)
    {
      current_state = multiplayer;
      in_game       = true;
    }
    else if (play_selected == ExitOp)
    {
      window.close();
    }
    if (diff_window == 0)
    {
      if (diff_selected == easy)
      {
        current_state         = singleplayer;
        Ai->curren_difficulty = Ai->easy;
        in_game               = true;
      }
      else if (diff_selected == medium)
      {
        current_state         = singleplayer;
        Ai->curren_difficulty = Ai->medium;
        in_game               = true;
      }
      else if (diff_selected == hard)
      {
        current_state         = singleplayer;
        Ai->curren_difficulty = Ai->hard;
        in_game               = true;
      }
    }
    else if (diff_window == 1)
    {
      current_state = in_menu;
      play_selected = SingleOp;
      diff_window   = 0;
      diff_selected = 0;
    }
  }
  if (event.key.code == sf::Keyboard::Q)
  {
    resetGame();
  }
}

void Game::resetGame()
{
  in_game       = false;
  add_ball = false;
  current_state = in_menu;
  play_selected = SingleOp;
  diff_window   = 0;
  diff_selected = 0;
  RenderHelper->renderReset();
}

void Game::addScoreRight(){

    RenderHelper->current_score_right++;
    RenderHelper->score_right.setString(std::to_string(RenderHelper->current_score_right));

}
void Game::addScoreLeft(){

    RenderHelper->current_score_left++;
     RenderHelper->score_left.setString(std::to_string(RenderHelper->current_score_left));

}