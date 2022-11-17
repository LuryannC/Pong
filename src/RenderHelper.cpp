#include "RenderHelper.h"
#include "Game.h"
#include <iostream>

RenderHelper::RenderHelper(sf::RenderWindow& game_window) : window(game_window){

}

bool RenderHelper::renderHud()
{

  if(!background_texture.loadFromFile("Data/Images/background.png")){
    std::cout << "Background texture did not load \n";
  }
  // Background
  background.setTexture(background_texture);
  background.setScale(
    window.getSize().x / background.getGlobalBounds().width,
    window.getSize().y / background.getGlobalBounds().height
  );

  // Game Title
  game_title.setString(" The Pong\n    Game");
  game_title.setFont(font_title);
  game_title.setFillColor(sf::Color(255,45,244));
  game_title.setCharacterSize(100);
  game_title.setPosition(window.getSize().x / 5 + 20, 40);

  // Play Game option
  play_text.setString("Play");
  play_text.setFont(font);
  play_text.setFillColor(sf::Color::Red);
  play_text.setCharacterSize(50);
  play_text.setOutlineColor(sf::Color::Red);
  play_text.setOutlineThickness(0);
  play_text.setPosition(window.getSize().x / 2 - 50 , 360);


  // Difficulty text
  difficulty_text.setString("Choose difficulty\n    (Right / Left)");
  difficulty_text.setFillColor(sf::Color::Red);
  difficulty_text.setOutlineColor(sf::Color::White);
  difficulty_text.setOutlineThickness(2.0f);
  difficulty_text.setFont(font);
  difficulty_text.setCharacterSize(40);
  difficulty_text.setPosition(window.getSize().x / 2 - 160, 380);

  // Difficulty selection
  diff_selection.setString("Easy");
  diff_selection.setFont(font);
  diff_selection.setFillColor(sf::Color::Red);
  diff_selection.setCharacterSize(50);
  diff_selection.setOutlineColor(sf::Color::Red);
  diff_selection.setOutlineThickness(0);
  diff_selection.setPosition(window.getSize().x / 2 - 50 , 520);

  // Return Text
  return_text.setString("Return");
  return_text.setFont(font);
  return_text.setFillColor(sf::Color(255,255,255));
  return_text.setCharacterSize(50);
  return_text.setOutlineColor(sf::Color::Red);
  return_text.setOutlineThickness(2.0f);
  return_text.setPosition(window.getSize().x / 2 - 86 , 610);


  // Multiplayer
  multiplayer_text.setString("Multiplayer");
  multiplayer_text.setFont(font);
  multiplayer_text.setFillColor(sf::Color(255,255,255));
  multiplayer_text.setCharacterSize(50);
  multiplayer_text.setOutlineColor(sf::Color::Red);
  multiplayer_text.setOutlineThickness(2.0f);
  multiplayer_text.setPosition(window.getSize().x / 2 - 150 , 465);

  // Extra ball text
  extra_ball.setString("SPACE for extra ball");
  extra_ball.setFont(font);
  extra_ball.setCharacterSize(25);
  extra_ball.setPosition(8, 8);
  extra_ball.setFillColor(sf::Color::White);
  extra_ball.setOutlineColor(sf::Color::Red);
  extra_ball.setOutlineThickness(2.0f);

  // in game help
  exit_key.setString("Q to exit");
  exit_key.setFont(font);
  exit_key.setFillColor(sf::Color::White);
  exit_key.setCharacterSize(25);
  exit_key.setOutlineColor(sf::Color::Red);
  exit_key.setOutlineThickness(2.0);
  exit_key.setPosition(window.getSize().x - 150 , 5);


  // Exit Game option
  exit_game.setString("Exit");
  exit_game.setFont(font);
  exit_game.setFillColor(sf::Color(255,255,255));
  exit_game.setOutlineColor(sf::Color::Red);
  exit_game.setOutlineThickness(2.0f);
  exit_game.setCharacterSize(50);
  exit_game.setPosition(window.getSize().x / 2 - 50 , 570);

  // Line
  rectangle.setPosition(window.getSize().x/2, 0);
  rectangle.setSize(sf::Vector2f(window.getSize().y, 4));
  rectangle.setFillColor(sf::Color::Red);
  rectangle.rotate(90.0f);

  // Game Over Screen
  game_over.setString("Game Over");
  game_over.setFont(font_title);
  game_over.setFillColor(sf::Color(255,45,244));
  game_over.setCharacterSize(100);
  game_over.setPosition(window.getSize().x / 2 - 352,100);


  // Scores
  score_left.setString(std::to_string(current_score_left));
  score_left.setFont(font);
  score_left.setPosition(window.getSize().x / 3, 20);
  score_left.setCharacterSize(80);
  score_left.setFillColor(sf::Color::Red);

  score_right.setString(std::to_string(current_score_right));
  score_right.setFont(font);
  score_right.setPosition(window.getSize().x / 1.63f, 20);
  score_right.setCharacterSize(80);
  score_right.setFillColor(sf::Color::Red);

  if (!font_title.loadFromFile("Data/Fonts/KGHAPPY.ttf")){
    std::cout << "Font did not load \n";
  }
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf")){
    std::cout << "Font did not load \n";
  }



  return true;

}

void RenderHelper::renderReset(){
  // Set left score to 0 and its position
  current_score_left = 0;
  score_left.setString(std::to_string(current_score_left));
  score_left.setPosition(window.getSize().x / 3, 20);

  // Same as above but for the right score
  current_score_right = 0;
  score_right.setString(std::to_string(current_score_right));
  score_right.setPosition(window.getSize().x / 1.63f, 20);

  // Change Q string position
  exit_key.setPosition(window.getSize().x - 150 , 5);
  exit_key.setCharacterSize(25);
}
