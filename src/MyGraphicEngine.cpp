#include "../include/MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
  //GraphicPrimitives::drawSpritedRect2D(0,0,0.5,0.5,1000,1000,tm);

  game->drawLogo();
  consol->draw();
  map->draw();
  if (game->getStarted() == true) {
    game->drawComponent();
  }
  //draw towers
  for (int i = 0; i < towers->size(); i++) {
    (*towers)[i]->draw();
  }
  //draw buttons
  for (int i = 0; i < buttons->size(); i++) {
    (*buttons)[i]->draw();
  }
  //draw monsters
  for (int i = 0; i < monsters->size(); i++) {
    (*monsters)[i]->draw();
  }
}
