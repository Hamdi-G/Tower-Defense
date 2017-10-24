#pragma once
#include "Game.h"
#include "Engine.h"
#include <iostream>
#include <math.h>
#include <unistd.h>


class MyControlEngine:public ControlEngine {
private:
    Game *game;
    std::vector<Button * > *buttons;
    std::vector<Tower * > *towers;
    std::vector<Monster * > *monsters;
    bool creating;
    bool boxActive;
    Map *C;
    Consol *consol;
    int selectedTower;
    int a,b;

public:
    MyControlEngine(Game * jeu_,Consol *consol_,Map *C_,std::vector<Tower * > * tous_,std::vector<Monster * > * mons_,std::vector<Button * > * bous_):game(jeu_),consol(consol_),C(C_),towers(tous_),monsters(mons_),buttons(bous_),creating(false),boxActive(false),selectedTower(-1),a(0),b(0){}

    virtual void MouseCallback(int button, int state, int x, int y) ;
    //virtual void KeyboardCallback(unsigned char key,int x, int y);
};
