#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Menu {
 protected:
 // rectangle shape for menu size
    RectangleShape* background;
    RectangleShape* how_to_play_bg;
    RectangleShape* control_bg;
    RectangleShape* save_bg;

    bool how_to_play_visible;
    bool control_visible;
    bool save_visible;
    bool isMainMenuOpen;

    int x, y;
    int selected_option;
    Font font;
    Text title;
    int length, width;
    int max_option;
  Text menu[4];
  bool turnOn;


 public:
    Menu(int len, int wid){
    length = len;
    width = wid;
    x = 300;
    y = 300;
    max_option = 4;
    turnOn = true;
    how_to_play_visible = false;
    control_visible = false;
    save_visible = false;
    isMainMenuOpen = false;

    // creating background — maybe change into another function
    background = new RectangleShape(Vector2f(length, width));
    background->setFillColor(Color::Red);
    background->setPosition(x, y);

    how_to_play_bg = new RectangleShape(Vector2f(length, width));
    how_to_play_bg->setFillColor(Color::White);
    how_to_play_bg->setPosition(x, y);

    control_bg = new RectangleShape(Vector2f(length, width));
    control_bg->setFillColor(Color::Blue);
    control_bg->setPosition(x, y);

    save_bg = new RectangleShape(Vector2f(length, width));
    save_bg->setFillColor(Color::Green);
    save_bg->setPosition(x, y);

    // loading font
    font.loadFromFile("textures/font_texture/TTF/dogica.ttf");
    if (!font.loadFromFile("textures/font_texture/TTF/dogica.ttf")) {
      std::cout << "error loading font" << std::endl;  // error testing
    }

    // buidling the title text
    title.setFont(font);
    title.setString("Title of Game");
    title.setCharacterSize(10);
    title.setFillColor(Color::Black);
    title.setPosition(x+10, y+10);

    // building options for menu

    // play button — closes menu and let's you play
    menu[0].setFont(font);
    menu[0].setString("play");
    menu[0].setCharacterSize(10);
    menu[0].setFillColor(Color::White);
    menu[0].setPosition(x+10, y+30);

   // how to play — opens new rectangle to run tutorial
    menu[1].setFont(font);
    menu[1].setString("how to play");
    menu[1].setCharacterSize(10);
    menu[1].setFillColor(Color::White);
    menu[1].setPosition(x+10, y+50);

    // controls button — opens new rectangle to show controls
    menu[2].setFont(font);
    menu[2].setString("controls");
    menu[2].setCharacterSize(10);
    menu[2].setFillColor(Color::White);
    menu[2].setPosition(x+10, y+70);

    // save button
    menu[3].setFont(font);
    menu[3].setString("save");
    menu[3].setCharacterSize(10);
    menu[3].setFillColor(Color::White);
    menu[3].setPosition(x+10, y+90);


    selected_option = 0;
    menu[selected_option].setFillColor(Color::Yellow);

    };


    void draw(RenderWindow* win){
        win->draw(*background);
        win->draw(title);
        for (int i = 0; i<max_option;i++){
            win->draw(menu[i]);
        }
    };

    void draw_htp(RenderWindow* win){
        win->draw(*how_to_play_bg);
    }

    void draw_control(RenderWindow* win){
        win->draw(*control_bg);
    }

    void draw_save(RenderWindow* win){
        win->draw(*save_bg);
    }

    void moveDown(){
    // Move the selection down
    //Check array bounds
    if  (selected_option +1 <= max_option){
        //Change text colour
        menu[selected_option].setFillColor(sf::Color::White);
        //Iterate array pos
        selected_option++;
        //Change text colour
        menu[selected_option].setFillColor(sf::Color::Yellow);
    } else{
        selected_option = 0;
    }
}
void moveUp(){
    // Move the selection up
    //Check array bounds
    if (selected_option -1 >= 0){
        // Set the current item's color to black
        menu[selected_option].setFillColor(sf::Color::White);
        selected_option--;
        // Set the new selected item's color to yellow
        menu[selected_option].setFillColor(sf::Color::Yellow);
    }
}


    // visibility function

    void set_visibility(bool visible) { turnOn = visible; }
    bool get_visibility() { return turnOn; }

    void set_htp_visi(bool visible){
        how_to_play_visible = visible;
    }
    bool get_htp_visi(){ return how_to_play_visible;}

    void set_control_visi(bool visible){
        control_visible = visible;
    }
    bool get_control_visi(){
        return control_visible;
    }

    void set_save_visi(bool visible){
        save_visible = visible;
    }
    bool get_save_visi(){
        return save_visible;
    }
    void setPressed(int selected){
        selected_option = selected;
    }
    int menuPressed(){
        return selected_option;
    };


    // ~Menu();
};
#endif
