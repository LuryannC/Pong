#ifndef PONGSFML_RENDERHELPER_H
#define PONGSFML_RENDERHELPER_H

#include <SFML/Graphics.hpp>

class RenderHelper
{
 public:
  RenderHelper(sf::RenderWindow& window);
  bool renderHud();
  void renderReset();

  sf::Text game_title;
  sf::Text play_text;
  sf::Text difficulty_text;
  sf::Text diff_selection;
  sf::Text return_text;
  sf::Text multiplayer_text;
  sf::Text extra_ball;
  sf::RectangleShape rectangle;
  sf::Sprite background;
  sf::Text exit_game;
  sf::Text game_over;
  sf::Text score_left;
  sf::Text score_right;
  sf::Text exit_key;
  int current_score_left = 0;
  int current_score_right = 0;



 private:
  sf::Font font_title;
  sf::Font font;
  sf::Texture background_texture;


  sf::RenderWindow& window;
};

#endif // PONGSFML_RENDERHELPER_H
