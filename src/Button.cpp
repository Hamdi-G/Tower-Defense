#include "../include/Button.h"

Button::Button(float posX_,float posY_,float width_,float height_,std::string label_,bool small_):posX(posX_),posY(posY_),width(width_),height(height_),label(label_),small(small_){}
void Button::draw(){
  GraphicPrimitives::drawFillRect2D(posX,posY,width,height,0.753f, 0.753f, 0.753f);
  char *cstr = new char[label.length() + 1];
  strcpy(cstr, label.c_str());
  if (small) {
    GraphicPrimitives::drawSmallText2D(cstr,posX+0.01f,posY+0.02f,0.251, 0.251, 0.251);
  }
  else
  GraphicPrimitives::drawText2D(cstr,posX+0.03f,posY+0.03f,0.251, 0.251, 0.251);
  delete [] cstr;
  GraphicPrimitives::drawOutlinedRect2D(posX,posY,width,height,0.502, 0.502, 0.502);
}
bool Button::onClick(float x,float y){
  return (x > posX && x < posX+width && y >= posY && y <= posY+height);
}
bool Button::withLabel(std::string s){
  return (s == label);
}
void Button::erase(){
  *this = Button(0,0,0,0,"");
}
