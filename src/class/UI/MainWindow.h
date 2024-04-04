//
// Created by mfauz on 04/04/2024.
//


#ifndef TUBES1_OOP_MAINWINDOW_H
#define TUBES1_OOP_MAINWINDOW_H


#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MainWindow {
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Mouse positions
    sf::Vector2i mousePosWindow;

    //Resources
    sf::Font font;

    //Text
    sf::Text uiText;

    //Game logic
    bool endGame;
    unsigned points;
    int health;

    //Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    //Private functions
    void initVariables();
    void initWindow();
    void initFonts();
    void initText();

public:
    MainWindow();
    ~MainWindow();

    //Accessors
    bool running() const;
    bool getEndGame() const;


    void pollEvents();
    void updateMousePositions();
    void updateText();
    void update();

    void renderText(sf::RenderTarget& target);
    void render();
};


#endif //TUBES1_OOP_MAINWINDOW_H
