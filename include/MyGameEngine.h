#pragma once
#include "Game.h"
#include "Engine.h"



#include <math.h>

class MyGameEngine:public GameEngine {
private:
    Game *game;
    Map *C;
    Consol *consol;
    std::vector<Monster * > *monsters;
    std::vector<Tower * > *towers;
    std::vector<Button * > *buttons;
    bool bb;

public:
    MyGameEngine(Game * jeu_,Consol *consol_,Map *C_,std::vector<Monster * > * mons_,std::vector<Tower * > * tous_,std::vector<Button * > * bous_):game(jeu_),consol(consol_),C(C_),monsters(mons_),towers(tous_),buttons(bous_),bb(false){}
    virtual void idle();

};
