#ifndef TEXT_BOX_H
#define TEXT_BOX_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Text_box {
 protected:
  RectangleShape* textbox;
  Text text;
  float length, width;
  Texture text_texture;
  bool isVisible;

 public:
  Text_box(float len, float wid) {
    length = len;
    width = wid;
    textbox = new RectangleShape(Vector2f(length, width));
    text_texture.loadFromFile("textures/text_box_texture.png");
    textbox->setTexture(&text_texture);
    textbox->setTextureRect(IntRect(0, 0, length, width));
    if (!text_texture.loadFromFile("textures/text_box_texture.png")) {
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

  ~Text_box() { delete[] textbox; };

  // getters and setters
  Text get_text() { return text; }
  void set_visible(bool visible) { isVisible = visible; }
  void set_text(Text _text) { text = _text; }
};

#endif