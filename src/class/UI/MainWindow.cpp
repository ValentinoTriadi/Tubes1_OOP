//
// Created by mfauz on 04/04/2024.
//

#include "MainWindow.h"


void MainWindow::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void MainWindow::initFonts()
{
    if (this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
    }
}

void MainWindow::initText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}

void MainWindow::initVariables() {
    this->window = nullptr;

    //Game logic
    this->endGame = false;
    this->mouseHeld = false;
}

MainWindow::MainWindow() {
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
}

MainWindow::~MainWindow() {
    delete this->window;
}


void MainWindow::pollEvents()
{
    //Event polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void MainWindow::updateMousePositions()
{
    /**
        @ return void

        Updates the mouse positions:
        - Mouse position relative to window (Vector2i)
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void MainWindow::updateText()
{
    std::stringstream ss;

    ss << "Points: " << this->points << "\n"
       << "Health: " << this->health << "\n";

    this->uiText.setString(ss.str());
}


void MainWindow::update()
{
    this->pollEvents();

    if (!this->endGame)
    {
        this->updateMousePositions();
        this->updateText();
    }

    // End game condition
    if (this->health <= 0)
        this->endGame = true;
}

void MainWindow::renderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}

void MainWindow::render()
{
    /**
        @return void

        - clear old frame
        - render objects
        - display frame in window

        Renders the game objects.
    */

    this->window->clear();

    //Draw game objects


    this->renderText(*this->window);

    this->window->display();
}

//Accessors
bool MainWindow::running() const
{
    return this->window->isOpen();
}

bool MainWindow::getEndGame() const
{
    return this->endGame;
}

