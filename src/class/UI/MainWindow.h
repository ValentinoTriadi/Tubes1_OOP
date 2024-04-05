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

#include "../Manager/GameManager/GameManager.hpp"

class MainWindow {
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    bool mouseHeld;

    //Resources
    sf::Font font;

    // Button
    sf::Sprite button1Image;
    sf::Texture button1Texture;
    sf::Sprite button2Image;
    sf::Texture button2Texture;

    //Text
    sf::Text uiText;

    //Game logic
    bool endGame;
    unsigned points;
    int health;

    //Game objects
    GameManager gameManager;

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

    void RunInitializeGameState();

    static void ChangeColorOnHover(sf::Sprite button, sf::Vector2f mousePosF);

    void renderButton();

    void RunStartNewGameButton();

    void RunContinueGameButton();
};


#endif //TUBES1_OOP_MAINWINDOW_H
