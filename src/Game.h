
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "Ball.h"
#include "Bat.h"
#include "Vector.h"
#include "RenderHelper.h"
#include "Ai.h"
#include <SFML/Graphics.hpp>

class Game
{

 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void movePaddles();
  void keyPressed(sf::Event event);
  void moveBall(float dt);
  void resetGame();
  void addScoreRight();
  void addScoreLeft();

  Bat* Bat;
  Ball* Ball[2];
  Vector* Vector[2];
  RenderHelper* RenderHelper;
  Ai* Ai;



 private:

  int n_balls = 2;
  bool add_ball = false;

  enum GameState {
    in_menu = 1,
    difficulty = 2,
    singleplayer = 3,
    multiplayer = 4,
    game_over = 5
  };
  GameState current_state = in_menu;

  enum OptionSelected {
    SingleOp = 1,
    MultipOp = 2,
    ExitOp = 3
  };
  int play_selected = SingleOp;
  sf::RenderWindow& window;
  bool in_game = false;
  int diff_window= 0;

  enum diff{
    easy = 1,
    medium = 2,
    hard = 3
  };
  int diff_selected = 0;
};

#endif // PONG_GAME_H
