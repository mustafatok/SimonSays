//
//  SimonSays.h
//  SimonSays
//

#ifndef __SimonSays__SimonSays__
#define __SimonSays__SimonSays__

#include <iostream>
#include <vector>
#include "DrawPrimitives.hpp"

class DisplayCallbacks{
public:
    void countDown();
    void colorSequence(ColorSequence colorSeq);
    void gameOver();
    void score(int score);

};
class SimonSays : public DisplayCallbacks{
private:
    int _row, _score;
    bool _isStarted;
    bool _inputState;
    bool _gameOver;
    ColorSequence colorSeq;
public:
    SimonSays();
    bool isStarted();
    void setStarted(bool started);
    bool isInputState();
    int row();
    int score();
    int randomColor();
    ColorSequence colorSequence();
    void processInput(int colorId);
    void gameOver();
    bool isGameOver();
    void handleInput(int buttonId, DisplayCallbacks* displayCallBack);

    void keyboardHandler(int Key);


};




#endif /* defined(__SimonSays__SimonSays__) */
