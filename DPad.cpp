//
//  DPad.cpp
//  RPGCollab
//
//  Created by Jordan Brown on 9/1/14.
//
//

#include "DPad.h"
DPad::DPad(){}
DPad::~DPad() {}
DPad *DPad::create(std::string base, std::string buttonImage, std::string pressedButtonImage, Point position){
    DPad *controller = new DPad();
    if (true)
    {
        // Set to autorelease
        controller->autorelease();
        controller->bg = Sprite::create(base);
        controller->bg->setPosition(position);
        controller->addChild(controller->bg,100);
        controller->up = MenuItemImage::create(buttonImage,pressedButtonImage);
        controller->down = MenuItemImage::create(buttonImage,pressedButtonImage);
        controller->left = MenuItemImage::create(buttonImage,pressedButtonImage);
        controller->right = MenuItemImage::create(buttonImage,pressedButtonImage);
        controller->up->setPosition(Point(controller->bg->getPosition().x, controller->bg->getPosition().y + controller->bg->getContentSize().height/2 - controller->up->getContentSize().height/2));
        controller->down->setPosition(Point(controller->bg->getPosition().x,controller->bg->getPosition().y - controller->bg->getContentSize().height/2 + controller->down->getContentSize().height/2));
        controller->right->setPosition(Point(controller->bg->getPosition().x + controller->bg->getContentSize().width/2 - controller->down->getContentSize().width/2, controller->bg->getPosition().y));
         controller->left->setPosition(Point(controller->bg->getPosition().x - controller->bg->getContentSize().width/2 + controller->down->getContentSize().width/2,controller->bg->getPosition().y));
        controller->right->setRotation(90);
        controller->down->setRotation(180);
        controller->left->setRotation(-90);
        Menu *menu = Menu::create(controller->up,controller->down,controller->left,controller->right,NULL);
        menu->setPosition(Point(0,0));
        controller->addChild(menu, 120);
        // assign color value
        
        return controller;
    }
    CC_SAFE_DELETE(controller);
    return NULL;
}
MenuItemImage *DPad::getButton(int button){
    MenuItemImage *result;
    switch (button) {
        case 8:
            result = DPad::up;
            break;
        case 2:
            result = DPad::down;
            break;
        case 6:
            result = DPad::right;
            break;
        case 4:
            result = DPad::left;
            break;
        default:
            break;
    }
    return result;
}
void DPad::setCorner(int corner){
    Point position;
	switch (corner) {
		case 1:
            position = Point(bg->getContentSize().width/2, Director::getInstance()->getWinSize().height - bg->getContentSize().height/2);
			break;
		case 2:
            position = Point(Director::getInstance()->getWinSize().width - bg->getContentSize().width/2,Director::getInstance()->getWinSize().height - bg->getContentSize().height/2);
			break;
		case 3:
			position = Point(bg->getContentSize().width/2,bg->getContentSize().height/2);
			break;
		case 4:
			position = Point(Director::getInstance()->getWinSize().width - bg->getContentSize().width/2,bg->getContentSize().height/2);
			break;
		default:
			break;
	}
	bg->setPosition(position);
	up->setPosition(Point(bg->getPosition().x,bg->getPosition().y + bg->getContentSize().height/2 - up->getContentSize().height/2));
	down->setPosition(Point(bg->getPosition().x,bg->getPosition().y - bg->getContentSize().height/2 + down->getContentSize().height/2));
	right->setPosition(Point(bg->getPosition().x + bg->getContentSize().width/2 - right->getContentSize().width/2,bg->getPosition().y));
	left->setPosition(Point(bg->getPosition().x - bg->getContentSize().width/2 + left->getContentSize().width/2,bg->getPosition().y));
}
