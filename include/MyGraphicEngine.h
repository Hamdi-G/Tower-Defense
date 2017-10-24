#pragma once
#include "Game.h"
#include "Engine.h"
#include "GraphicPrimitives.h"
#include <unistd.h>
#include <string>


class MyGraphicEngine:public GraphicEngine {
private:
  Game *game;
  Map *map;
  Consol *consol;
  //TextureManager *tm;
  std::vector<Tower * > *towers;
  std::vector<Monster * > *monsters;
  std::vector<Button * > *buttons;

public:
  MyGraphicEngine(Game * jeu_,Consol * consol_,Map * C,std::vector<Tower * > * tous_,std::vector<Monster * > * mons_,std::vector<Button * > * bous_):
  game(jeu_),
  consol(consol_),
  map(C),
  towers(tous_),
  monsters(mons_),
  buttons(bous_)
  {/*
    std::string s = "../include/config/download.bmp";
    char *cstr7 = new char[s.length() + 1];
    strcpy(cstr7, s.c_str());
    tm = new TextureManager(cstr7, 1,1);
    delete [] cstr7;*/
  }
  virtual void Draw();
};
