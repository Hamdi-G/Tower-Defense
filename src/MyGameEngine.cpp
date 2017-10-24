#include "../include/MyGameEngine.h"

void MyGameEngine::idle(){
  if (game->getLife() == 0) {
    bb = false;
    game->restart();
    consol->write(".                                                      You lose! you can play again");
  }
  if (game->getWM().getWaveNumber() == game->getWM().getMaxWave() && monsters->size() == 0) {
    bb = false;
    game->restart();
    consol->write(".                                                       You win! you can play again");
  }

  if (monsters->size() != 0 ) {
    if (towers->size() != 0 ) {
      for (int i = 0; i < towers->size(); i++) {
        (*towers)[i]->shoot(monsters);
      }
    }
  }

  for (int i = 0; i < monsters->size(); i++) {
    (*monsters)[i]->move();
    if ((*monsters)[i]->getTravled() == 106  &&  game->getWM().getnbMonsters()) {
      monsters->push_back(game->getWM().getNextMonster(C));
    }
  }

  if (monsters->size() != 0 ) {
    for (int i = 0; i < monsters->size(); i++) {
      int a = static_cast<int>((*monsters)[i]->getPosX());
      int b = static_cast<int>((*monsters)[i]->getPosY());
      if (monsters->size() != 0 ) {
        if ((*monsters)[i]->getLife() < 0) {
          game->addCoins((*monsters)[i]->getCoins());
          if ((*monsters)[i]->getLabel() == "ExplosiveMonster") {
            float x1 = (*monsters)[i]->getPosX();
            float y1 = (*monsters)[i]->getPosY();
            for (size_t k = 0; k < monsters->size(); k++) {
              if (k != i) {
                float x2 = (*monsters)[k]->getPosX();
                float y2 = (*monsters)[k]->getPosY();
                float distance = sqrt((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2));
                if (distance < 2 ) {
                  (*monsters)[k]->ReceiveDamage(300);
                }
              }
            }
          }
          delete (*monsters)[i];
          monsters->erase(monsters->begin()+i);
        }
      }
      if (a == C->getEndPath().getX() && b == C->getEndPath().getY() && game->getLife() > 0) {
        delete (*monsters)[i];
        monsters->erase(monsters->begin()+i);
        game->decrLife();
      }
    }
  }
  if (game->getWM().getWaveNumber() < game->getWM().getMaxWave()) {
    if (game->getStarted() && monsters->size() == 0 && bb == false) {
      for (int k = 0; k < buttons->size(); k++) {
        if ((*buttons)[k]->withLabel("Next wave") == false && (*buttons)[k]->withLabel("Save") == false) {
          buttons->push_back(new Button(-0.15f,-0.8f,0.3f,0.1f,"Next wave"));
          buttons->push_back(new Button(-0.9f,0.1f,0.18f,0.1f,"Save"));
          bb = true;
        }
      }
    }
    else if (monsters->size() > 0) {
      bb = false;
      consol->write("                                     you can upgrade towers level anytime");
    } else if (monsters->size() == 0 && game->getWM().getWaveNumber() > 0) {
      consol->write("                                   get ready for the next wave of monsters!");
    }
  }
}
