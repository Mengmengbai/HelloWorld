#include "HelloWorldScene.h"
#include "GameScene.h"


USING_NS_CC;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();      //这里是调用系统默认的init
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();  //这里是调用了Helloworld的init

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	

	auto backGround = Sprite::create("Background.png");
	backGround->setAnchorPoint(Vec2::ZERO);
	backGround->setPosition(Vec2(0,0));
	this->addChild(backGround);

	auto LablePlace = Label::createWithBMFont("fonts/fnt2.fnt","place");
	auto LablePlaceItem = MenuItemLabel::create(LablePlace,CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
	LablePlaceItem->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	LablePlaceItem->setTag(PLAC_TAG);
	
	auto LablePlyx = Label::createWithBMFont("fonts/fnt2.fnt","flyx");
	auto LablePlyxItem = MenuItemLabel::create(LablePlyx,CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
	LablePlyxItem->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+100));
	LablePlyxItem->setTag(FLYX_TAG);
	
	auto LablePlyy = Label::createWithBMFont("fonts/fnt2.fnt","flyy");
	auto LablePlyyItem = MenuItemLabel::create(LablePlyy,CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
	LablePlyyItem->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+200));
	LablePlyyItem->setTag(FLYY_TAG);

//	auto setItem = MenuItemImage::create("Go-up.png","Go-down.png",CC_CALLBACK_1     (HelloWorld::menuCloseCallback,this));
//	setItem->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+200));

	auto menu = Menu::create(LablePlaceItem,LablePlyyItem,LablePlyxItem,NULL);
	menu->setPosition(Vec2::ZERO);
	
	this->addChild(menu);



    return true;
}

void HelloWorld::update(float dt)
{
	auto label = this->getChildByTag(123);

	label->setPosition(label->getPosition() + Vec2(2.0,-2.0));



	
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	auto GMScene = Scene::create();
	auto GMLayer = GameScene::create();
	GMScene->addChild(GMLayer);

	auto ItemTag = (MenuItem*)pSender;
	GMLayer->setTag(ItemTag->getTag());

//	auto GameSceneset = GameScene::createScene();
	auto tGs = TransitionSplitCols::create(1.0f,GMScene);

	Director::getInstance()->pushScene(tGs);



}




//	unscheduleUpdate();
/*
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
	*/



////////////////////菜单按钮////////////////
 /*   
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto beijing = Sprite::create("/menu/setting-back.png");
	beijing->setAnchorPoint(Vec2(0.5,0.5));
	beijing->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	this->addChild(beijing);

	auto soundOn = MenuItemImage::create("menu/on.png","menu/on.png");
	auto soundOffItem = MenuItemImage::create("menu/on.png","menu/off.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
	auto soundOff = MenuItemImage::create("menu/off.png","menu/off.png");
	soundOffItem->setPosition(Director::getInstance()->convertToGL(Vec2(802,360)));


	auto soundOnItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuCloseCallback,this),soundOn,soundOff,NULL);
	soundOnItem->setPosition(Director::getInstance()->convertToGL(Vec2(802,200)));

	

	auto menus = Menu::create(soundOnItem,soundOffItem,NULL);
	menus->setPosition(Vec2::ZERO);
	this->addChild(menus);
	*/
