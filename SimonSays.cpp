//
//  SimonSays.cpp
//  SimonSays
//

#include "SimonSays.h"

void DisplayCallbacks::countDown(){
    std::cout << "10 - 9 - 8 - 7 - 6 - 5 - 4 - 3 - 2 - 1 - 0" << std::endl;
}
void DisplayCallbacks::colorSequence(ColorSequence colorSeq){
    for (int i = 0; i < colorSeq.size(); ++i) {
        std::string str = "";
        str += colorSeq.at(i) == COLOR_RED?"R":"";
        str += colorSeq.at(i) == COLOR_GREEN?"G":"";
        str += colorSeq.at(i) == COLOR_BLUE?"B":"";
        str += colorSeq.at(i) == COLOR_YELLOW?"Y":"";
        std::cout << str << " ";
    }
    std::cout << std::endl;
}
void DisplayCallbacks::gameOver(){
    std::cout << "Game Over" << std::endl;
}

void DisplayCallbacks::score(int score){
    std::cout << "Score: " << score << std::endl;
}

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
    if(_gameOver){
        _score = 0;
        _gameOver = false;
        colorSeq.clear();
    }
    _row = -1;
    colorSeq.push_back(randomColor());
    _inputState = true;
    return colorSeq;
}
void SimonSays::gameOver(){
    _gameOver = true;
    setStarted(false);
    _inputState = false;
}
bool SimonSays::isGameOver(){
    return _gameOver;
}
void SimonSays::processInput(int colorId){
    std::cout << colorSeq.size() << " " << _row + 1 << std::endl;
    
    if(colorId == -1 || _gameOver){
        gameOver();
        return;
    }
    ++_row;
    if(colorSeq.size() <= _row || !isInputState()){
        _inputState = false;
        return;
    }

    if(colorSeq.at(_row) == colorId){
        _score++;
    }else{
        gameOver();
    }
    
    if(_row + 1 >= colorSeq.size()){
        _inputState = false;
    }else{
        _inputState = true;
    }
   
}

void SimonSays::keyboardHandler(int Key)
{
    switch(Key)
    {
        case GLFW_KEY_S: handleInput(START_MARKER, this); break;
        case GLFW_KEY_R: handleInput(COLOR_RED, this); break;
        case GLFW_KEY_G: handleInput(COLOR_GREEN, this); break;
        case GLFW_KEY_B: handleInput(COLOR_BLUE, this); break;
        case GLFW_KEY_Y: handleInput(COLOR_YELLOW, this); break;
        case GLFW_KEY_ESCAPE:
            exit(1); 
            break;
    };
}

void SimonSays::handleInput(int buttonId, DisplayCallbacks* displayCallBack){
    
    if (buttonId == START_MARKER) {
        setStarted(true);
        displayCallBack->countDown();
        displayCallBack->colorSequence(colorSequence());
    }else{
        if(isStarted()){
            if(!isInputState()){
                std::cout << "Seq" << std::endl;
                displayCallBack->colorSequence(colorSequence());
            }else{
                processInput(buttonId);
                if(_gameOver){
                    displayCallBack->gameOver();
                }else{
                    displayCallBack->score(score());
                    if(!isInputState()){
                        std::cout << "Seq" << std::endl;
                        displayCallBack->colorSequence(colorSequence());
                    }
                }
            }
        }
    }
    
}






