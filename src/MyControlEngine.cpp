#include "../include/MyControlEngine.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
  float x_= ((x-400) / 400.f);
  float x__ = floorf(x_ * 10) / 10;
  float y_ = ((y-358)/ -358.f);
  float y__ = floorf(y_ * 10) / 10;
  int i_ = static_cast<int>(x__ * 10) + 6;
  int j_ = static_cast<int>(y__ * 10) + 6;

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

    //close all active boxes
    for (int k = 0; k < towers->size(); k++) {
      (*towers)[k]->setBox(false);
    }

    //Activing a tower box's by clicking on
    if ((x__ >= -0.6f && x__ < 0.6f) && (y__ >= -0.6f && y__ < 0.6f )) {
      if ((C->getSquares())[i_][j_].getEmpty() == false) {
        for (int k = 0; k < towers->size(); k++) {
          if ((*towers)[k]->getPosX() == i_ && (*towers)[k]->getPosY() == j_) {
            (*towers)[k]->setBox(true);
            boxActive = true;
            buttons->push_back(new Button(0.65f + 0.1,-0.2f + 0.05f,0.1f,0.06f,"Level+",true));
            a=i_;
            b=j_;
          }
        }
      }
    }

    //choosing Towers
    if (i_ >= 0 && i_ <= 3 && j_ >= 12 && j_<= 15 ) {
      selectedTower = 1;
    }
    else if (i_ >= 4 && i_ <= 7 && j_ >= 12 && j_<= 15) {
      selectedTower = 2;
    }
    else if (i_ >= 8 && i_ <= 11 && j_ >= 12 && j_<= 15 ) {
      selectedTower = 3;
    }

    //putting them on the map
    if (((x__ >= -0.6f && x__ < 0.6f) && (y__ >= -0.6f && y__ < 0.6f )) && !((C->getSquares())[i_][j_].getPath()) && ((C->getSquares())[i_][j_].getEmpty()) && creating == false  && game->getStarted() == true && selectedTower != -1) {
      switch (selectedTower) {
        case 1:
        towers->push_back(new BlueTower(i_,j_));
        if (game->getCoins() - (*towers)[towers->size()-1]->getPrice() >= 0)   {
          game->removeCoins((*towers)[towers->size()-1]->getPrice());
          (C->getSquares())[i_][j_].setEmpty(false);
        }
        else{
          delete (*towers)[towers->size()-1];
          towers->erase(towers->begin()+towers->size()-1);
        }
        break;
        case 2:
        towers->push_back(new GreenTower(i_,j_));
        if (game->getCoins() - (*towers)[towers->size()-1]->getPrice() >= 0)   {
          game->removeCoins((*towers)[towers->size()-1]->getPrice());
          (C->getSquares())[i_][j_].setEmpty(false);
        }
        else{
          delete (*towers)[towers->size()-1];
          towers->erase(towers->begin()+towers->size()-1);
        }
        break;
        case 3:
        towers->push_back(new RedTower(i_,j_));
        if (game->getCoins() - (*towers)[towers->size()-1]->getPrice() >= 0)   {
          game->removeCoins((*towers)[towers->size()-1]->getPrice());
          (C->getSquares())[i_][j_].setEmpty(false);
        }
        else{
          delete (*towers)[towers->size()-1];
          towers->erase(towers->begin()+towers->size()-1);
        }
        break;
      }
    }

    //creating path
    if (((x__ >= -0.6f && x__ < 0.6f) && (y__ >= -0.6f && y__ < 0.6f )) && !((C->getSquares())[i_][j_].getPath()) && ((C->getSquares())[i_][j_].getEmpty()) && creating == true) {
      if (C->getStartPath() == Square(-1,-1) && (i_ == 0 || i_ == 11 || j_ == 0 || j_ == 11)) {
        C->setStartPath((C->getSquares())[i_][j_]);
      }
      else if (!(C->getStartPath() == Square(-1,-1)) && C->getEndPath() == Square(-1,-1) && (i_ == 0 || i_ == 11 || j_ == 0 || j_ == 11)) {
        C->setEndPath((C->getSquares())[i_][j_]);
      }
      (C->getSquares())[i_][j_].setPath(true);
      (C->getSquares())[i_][j_].setEmpty(false);
    }

    //on every botton click
    for (int i = 0; i < buttons->size(); i++) {
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("New")) {
        for (int k = 0; k < buttons->size(); k++) {
          (*buttons)[k]->erase();
        }
        buttons->push_back(new Button(-0.4f,-0.8f,0.3f,0.1f,"Start Game"));
        buttons->push_back(new Button(0.1,-0.8f,0.33f,0.1f,"Change Map"));
        consol->write("                                        you can play with this default map or with others");
        C->setMap(1);

      }

      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Load")) {
        game->load();
        for (int k = 0; k < buttons->size(); k++) {
          (*buttons)[k]->erase();
        }
        buttons->push_back(new Button(-0.9f,0.1f,0.18f,0.1f,"Save"));
        buttons->push_back(new Button(-0.9f,-0.1f,0.15f,0.1f,"Exit"));
        game->setStarted();
        consol->write("Welcome back!");
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Save")) {
        game->save();
      }

      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Change Map")){
        consol->write("                                           Choose a map or create your custom one");
        for (int k = 0; k < buttons->size(); k++) {
          if ((*buttons)[k]->withLabel("Change Map")) {
            (*buttons)[k]->erase();
          }
        }
        buttons->push_back(new Button(-0.9f,0.3f,0.2f,0.1f,"Map 1"));
        buttons->push_back(new Button(-0.9f,0.1f,0.2f,0.1f,"Map 2"));
        buttons->push_back(new Button(-0.9f,-0.1f,0.2f,0.1f,"Map 3"));
        buttons->push_back(new Button(-0.9f,-0.3f,0.2f,0.1f,"Map 4"));
        buttons->push_back(new Button(0.65f,0.0f,0.31f,0.1f,"Create Map"));
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Map 1")){
        C->setMap(1);
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Map 2")){
        C->setMap(2);
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Map 3")){
        C->setMap(3);
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Map 4")){
        C->setMap(4);
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Create Map")){
        consol->write("                                              define your custom map and click Save");
        creating = true;
        C->erase();
        for (int k = 0; k < buttons->size(); k++) {
          if (((*buttons)[k]->withLabel("Map 1")) || ((*buttons)[k]->withLabel("Map 2")) || ((*buttons)[k]->withLabel("Map 3")) || ((*buttons)[k]->withLabel("Map 4")) || ((*buttons)[k]->withLabel("Create Map")) || ((*buttons)[k]->withLabel("Start Game"))) {
            (*buttons)[k]->erase();
          }
        }
        buttons->push_back(new Button(0.7f,0.1f,0.22f,0.1f,"Clear all"));
        buttons->push_back(new Button(0.7f,-0.1f,0.25f,0.1f,"Save map"));
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Start Game")){
        for (int k = 0; k < buttons->size(); k++) {
          (*buttons)[k]->erase();
        }
        creating = false;
        buttons->push_back(new Button(-0.9f,0.1f,0.18f,0.1f,"Save"));
        buttons->push_back(new Button(-0.9f,-0.1f,0.15f,0.1f,"Exit"));
        game->setStarted();
        consol->write("                           to fight the monsters, you have to place towers on the map");
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Exit")) {
        game->restart();
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Clear all")) {
        C->erase();
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Save map")) {
        if (!(C->getStartPath() == Square(-1,-1) || C->getEndPath() == Square(-1,-1))) {
          for (int k = 0; k < buttons->size(); k++) {
            if (((*buttons)[k]->withLabel("Clear all")) || ((*buttons)[k]->withLabel("Save map"))) {
              (*buttons)[k]->erase();
            }
          }
          C->save();
          buttons->push_back(new Button(-0.4f,-0.8f,0.3f,0.1f,"Start Game"));
          consol->write("                                                            Saved with success");
        } else
        consol->write("                                                            your map isn't correct");
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Level+")) {
        for (int k = 0; k < towers->size(); k++) {
          if ((*towers)[k]->getPosX() == a && (*towers)[k]->getPosY() == b) {
            if (game->getCoins() - ((*towers)[towers->size()-1]->getPrice() * 2) >= 0) {
              (*towers)[k]->upgradeLevel();
              game->removeCoins((*towers)[k]->getPrice());
            }
          }
        }
        for (int k = 0; k < buttons->size(); k++) {
          if ((*buttons)[k]->withLabel("Level+")) {
            (*buttons)[k]->erase();
          }
        }
      }
      if ((*buttons)[i]->onClick(x_,y_) && (*buttons)[i]->withLabel("Next wave")) {
        game->getWM().getMaxWave();
        game->getWM().incrWave();
        monsters->push_back(game->getWM().getNextMonster(C));
        for (int k = 0; k < buttons->size(); k++) {
          if (((*buttons)[k]->withLabel("Next wave"))  || ((*buttons)[k]->withLabel("Save"))) {
            (*buttons)[k]->erase();
          }
        }
      }
    }
  }
}

/*void MyControlEngine::KeyboardCallback(unsigned char key,int x, int y){
  if (key == 'g' && game->getStarted()) {
    monsters->push_back(new StrongMonster(C));
  }
}*/
