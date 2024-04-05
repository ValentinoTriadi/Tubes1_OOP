//
// Created by mfauz on 04/04/2024.
//

#include "MainWindow.h"



void MainWindow::initWindow() {
    this->videoMode.height = 720;
    this->videoMode.width = 1024;
    this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Close);
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
    this->uiText.setString("HELLO WORLD");
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

void MainWindow::ChangeColorOnHover(sf::Sprite button, sf::Vector2f mousePosF){
    if ( button.getGlobalBounds().contains( mousePosF ) )
    {
        button.setColor( sf::Color( 250, 20, 20 ) );
    }
    else
    {
        button.setColor( sf::Color( 255, 255, 255 ) );
    }
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
            case sf::Event::MouseButtonPressed:
                if (this->ev.mouseButton.button == sf::Mouse::Left)
                    this->mouseHeld = true;

                // Check if mouse is inside button 1 bounding box
                if ( button1Image.getGlobalBounds().contains( static_cast<sf::Vector2f>( this->mousePosWindow ) ) )
                {
                    // Button 1 clicked
                    // Start new game
                    RunStartNewGameButton();
                }

                // Check if mouse is inside button 2 bounding box
                if ( button2Image.getGlobalBounds().contains( static_cast<sf::Vector2f>( this->mousePosWindow ) ) )
                {
                    // Button 2 clicked
                    // Continue game
                    gameManager.ContinueGame();
                }

                break;
            case sf::Event::MouseButtonReleased:
                if (this->ev.mouseButton.button == sf::Mouse::Left)
                    this->mouseHeld = false;
                break;
            case sf::Event::MouseMoved:
                // Get mouse position
                sf::Vector2i mousePos = sf::Mouse::getPosition( *this->window );
                sf::Vector2f mousePosF = sf::Vector2f( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                // Check if mouse is inside button 1 bounding box
                ChangeColorOnHover( button1Image, mousePosF );
                // Check if mouse is inside button 2 bounding box
                ChangeColorOnHover( button2Image, mousePosF );
                break;
        }
    }
}

void MainWindow::RunStartNewGameButton(){
    gameManager.StartNewGame();
    gameManager.StartTurn();
}

void MainWindow::RunContinueGameButton(){
    gameManager.ContinueGame();
    gameManager.StartTurn();
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

}


void MainWindow::update()
{
    this->pollEvents();

    if (!this->endGame)
    {
        this->updateMousePositions();
        this->updateText();
    }
}

void MainWindow::renderButton()
{
    this->window->draw( button1Image );
    this->window->draw( button2Image );
}

void MainWindow::renderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}

void MainWindow::render()
{
    this->window->clear();
    this->renderButton();
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

void MainWindow::RunInitializeGameState()
{
    // Create 2 button
    // Load button image

    button1Texture.loadFromFile( "Assets/button1.png" );
    button1Image.setTexture( button1Texture );

    button2Texture.loadFromFile( "Assets/button2.png" );
    button2Image.setTexture( button2Texture );

    // Button 1: Start New Game
    // Button 2: Continue Game
    button1Image.setPosition( 50.0f, 300.0f );
    button2Image.setPosition( 400.0f, 300.0f );
}

