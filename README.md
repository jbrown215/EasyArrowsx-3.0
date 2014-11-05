EasyArrowsx-3.0
===============

Easy Arrows for cocos2d redone for cocos2d-x 3.0+


In the scene you want the controller, add this to the init:

  .h 
  =================
  #include "DPad.h"
  =================
  DPad *controller;
  
  
  .cpp
  ==============================================================================================
  controller = DPad::create("Base01.png", "Button01.png", "ButtonPressed01.png", Point(0,0));
    controller->setCorner(x); //replace x with a corner number (1, 2, 3, or 4)
    this->addChild(controller);
    // in the update function:
    //dpad input
    if (controller->getButton(kDirectionDown)->isSelected()) {
        CCLOG("Down button is pressed!");
    }
    else if (controller->getButton(kDirectionUp)->isSelected()) {
        CCLOG("Up button is pressed!");
    }
    else if (controller->getButton(kDirectionLeft)->isSelected()) {
        CCLOG("Left button is pressed!");
    }
    else if (controller->getButton(kDirectionRight)->isSelected()) {
        CCLOG("Right button is pressed!");
    }
    
