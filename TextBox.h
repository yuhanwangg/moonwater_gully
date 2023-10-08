#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class TextBox {
 protected:
  RectangleShape* textbox;
  Text text;
  float length, width;
  Texture textTexture;
  bool isVisible;

 public:
  TextBox(float len, float wid) {
    length = len;
    width = wid;
    textbox = new RectangleShape(Vector2f(length, width));
    textTexture.loadFromFile("textures/text_box_texture.png");
    textbox->setTexture(&textTexture);
    textbox->setTextureRect(IntRect(0, 0, length, width));
    if (!textTexture.loadFromFile("textures/text_box_texture.png")) {
      std::cout << "error loading texture" << std::endl;
    }
    textbox->setPosition(500, 500);
    isVisible = true;
  };

  void draw(RenderWindow* win) {
    win->draw(*textbox);
    // if (isVisible == true) {
    //   win->draw(*textbox);
    // }
  };

  ~TextBox() { delete[] textbox; };

  // getters and setters
  Text get_text() { return text; }
  void set_visible(bool visible) { isVisible = visible; }
  void set_text(Text _text) { text = _text; }
};

#endif