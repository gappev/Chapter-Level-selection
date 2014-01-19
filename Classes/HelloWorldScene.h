#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CCScrollLayer.h"

using namespace cocos2d;

class ChapterSelection : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);

    CREATE_FUNC(ChapterSelection);
    
private:
    CCScrollLayer* scrollLayer;
    void planet1Selected();
    void planet2Selected();
    void planet3Selected();
    CCLayer *createLayerWith(const char* sprite, const char* sprite_pressed, SEL_MenuHandler t,const char* additionalText, ccColor3B additionalTextColor);
};

#endif // __HELLOWORLD_SCENE_H__
