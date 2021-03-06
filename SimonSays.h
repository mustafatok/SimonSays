//
//  SimonSays.h
//  SimonSays
//

#ifndef __SimonSays__SimonSays__
#define __SimonSays__SimonSays__

#include <iostream>
#include <vector>
#include "DrawPrimitives.hpp"
#include <sstream>

class DisplayCallbacks{
public:
    virtual void countDown();
    virtual void colorSequence(ColorSequence colorSeq);
    virtual void gameOver();
    virtual void score(int score);

};


class SimonSays : public DisplayCallbacks{
private:
    int _row, _score, _lives;
    bool _isStarted;
    bool _inputState;
    bool _gameOver;
    ColorSequence colorSeq;
    DisplayCallbacks* displayCallback;
public:
    SimonSays();
    bool isStarted();
    void setStarted(bool started);
    bool isInputState();
    void initGame();
    int row();
    int score();
    int randomColor();
    ColorSequence colorSequence(bool repeat);
    void processInput(int colorId);
    void gameOver();
    bool isGameOver();
    void handleInput(int buttonId);
    void setDisplayCallback(DisplayCallbacks* displayCallback);
    void keyboardHandler(int Key);
    int getLives();
    std::string getStatisticsScreen();

};




#endif /* defined(__SimonSays__SimonSays__) */
