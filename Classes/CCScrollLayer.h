//  CCScrollLayer.h
//  Museum
//
//  Created by GParvaneh on 29/12/2010.
//  Copyright 2010 All rights reserved.
//  Ported to C++ by Lior Tamam on 03/04/2011
//  Cleaned for Cocos2d-x V2.x by @HermanJakobi (01/12/12)
#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class CCScrollLayer : public cocos2d::CCLayer
{
    
public:
    
	static CCScrollLayer* create(cocos2d::CCArray* layers,int widthOffset);
	
    bool init(cocos2d::CCArray *layers,int widthOffset);
    
    // Holds the current height and width of the screen
	int scrollHeight;
	int scrollWidth;
	
	// Holds the height and width of the screen when the class was inited
	int startHeight;
	int startWidth;
	
	// Holds the current page being displayed
	int currentScreen;
	
	// A count of the total screens available
	int totalScreens;
	
	// The initial point the user starts their swipe
	int startSwipe;
    
	void moveToPage(int page);
	void moveToNextPage();
	void moveToPreviousPage();
	    
    virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    
    virtual void onEnter();
	virtual void onExit();
    
};