#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* ChapterSelection::scene()
{
    CCScene *scene = CCScene::create();
    ChapterSelection *layer = ChapterSelection::create();
    scene->addChild(layer);
    return scene;
}

bool ChapterSelection::init()
{
    if ( !CCLayerColor::initWithColor(ccc4(241, 241, 241, 255))     )
    {
        return false;
    }
    setTouchEnabled(true);

    CCArray *arr = CCArray::create();
    arr->addObject(createLayerWith("planet1.png", "planet1_pressed.png", menu_selector(ChapterSelection::planet1Selected), "Highscore: Over 9000!", ccc3(192, 57, 43)));
    arr->addObject(createLayerWith("planet2.png", "planet2_pressed.png", menu_selector(ChapterSelection::planet2Selected), "Highscore: 8750", ccc3(192, 57, 43)));
    arr->addObject(createLayerWith("planet3.png", "planet3_pressed.png", menu_selector(ChapterSelection::planet3Selected), "Highscore: 198450", ccc3(192, 57, 43)));
    arr->retain();
    
    scrollLayer = CCScrollLayer::create(arr, 500);
    scrollLayer->setContentSize(CCSizeMake(1136, 640));
    scrollLayer->setPosition(ccp(0, 0));
    
    addChild(scrollLayer);
    return true;
}

CCLayer* ChapterSelection::createLayerWith(const char *sprite, const char *sprite_pressed, SEL_MenuHandler menuHandler,const char *additionalText, ccColor3B additionalTextColor)
{
    CCMenuItemImage *image = CCMenuItemImage::create(sprite, sprite_pressed,this,menuHandler);
    CCMenuItemFont *itemText = CCMenuItemFont::create(additionalText);
    itemText->setColor(additionalTextColor);
    
    CCMenu *menu = CCMenu::create(image, itemText, NULL);
    menu->alignItemsVerticallyWithPadding(50.0f);
    
    CCLayer* containter = CCLayer::create();
    containter->addChild(menu);
    return containter;
}

void ChapterSelection::planet1Selected()
{
    if(scrollLayer->currentScreen != 1)
        scrollLayer->moveToPage(1);
}

void ChapterSelection::planet2Selected()
{
    if(scrollLayer->currentScreen != 2)
        scrollLayer->moveToPage(2);
}

void ChapterSelection::planet3Selected()
{
    if(scrollLayer->currentScreen != 3)
        scrollLayer->moveToPage(3);
}

void ChapterSelection::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}