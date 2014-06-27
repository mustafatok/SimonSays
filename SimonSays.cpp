//
//  SimonSays.cpp
//  SimonSays
//

#include "SimonSays.h"

SimonSays::SimonSays(){
    setStarted(false);
    _inputState = 0;
    _row = -1;
    _score = 0;
    _gameOver = false;
}
bool SimonSays::isStarted(){
    return _isStarted;
}
void SimonSays::setStarted(bool started){
    if (started == true) {
        colorSeq.clear();
    }
    this->_isStarted = started;
}
int SimonSays::row(){
    return _row;
}

int SimonSays::score(){
    return _score;
}

int SimonSays::randomColor(){
	return (rand() % 4) + 1;
}

bool SimonSays::isInputState(){
    return _inputState;
}

std::vector<int> SimonSays::colorSequence(){
    //TODO Not finished check gameover state..
    
//    if(_gameOver){
//        _score = 0;
//        _gameOver = false;
//    }
    _row = -1;
    colorSeq.push_back(randomColor());
    _inputState = true;
    return colorSeq;
}

void SimonSays::processInput(int colorId){
    // TODO Check again...
    std::cout << colorSeq.size() << " " << _row + 1 << std::endl;
    if(colorSeq.size() <= _row + 1 || !isInputState()){
        _inputState = false;
        return;
    }

    if(colorSeq.at(++_row) == colorId){
        _score++;
        std::cout << "Score: " << _score << std::endl;
    }else{
        _gameOver = true;
        _inputState = false;
    }
    
    if(_row + 1 >= colorSeq.size()){
        std::cout << "Instatefalse: " << std::endl;

        _inputState = false;
    }else{
        _inputState = true;
    }
   
}
