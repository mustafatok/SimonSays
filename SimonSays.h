//
//  SimonSays.h
//  SimonSays
//

#ifndef __SimonSays__SimonSays__
#define __SimonSays__SimonSays__

#include <iostream>
#include <vector>
class SimonSays {
private:
    int _row, _score;
    bool _isStarted;
    bool _inputState;
    bool _gameOver;
    std::vector<int> colorSeq;
public:
    SimonSays();
    bool isStarted();
    void setStarted(bool started);
    bool isInputState();
    int row();
    int score();
    int randomColor();
    std::vector<int> colorSequence();
    void processInput(int colorId);
};




#endif /* defined(__SimonSays__SimonSays__) */
