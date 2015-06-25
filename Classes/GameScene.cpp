#include "GameScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;




Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();      //这里是调用系统默认的init
    
    // 'layer' is an autorelease object
	auto layer = GameScene::create();  //这里是调用了Helloworld的init

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
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

	auto setItem = MenuItemImage::create("Back-up.png","Back-down.png",CC_CALLBACK_1(GameScene::menuCloseCallback,this));
	setItem->setPosition(Vec2(90,visibleSize.height-50));

	auto goItem = MenuItemImage::create("Go-up.png","Go-down.png",CC_CALLBACK_1(GameScene::action,this));
	goItem->setPosition(Vec2(visibleSize.width-100,80));

	auto menu = Menu::create(setItem,goItem,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	sHero = Sprite::create("hero.png");
	sHero->setPosition(Vec2(visibleSize.width/2-150,visibleSize.height/2));
	this->addChild(sHero);

	auto sHero1 = Sprite::create("hero.png");
	sHero1->setPosition(Vec2(visibleSize.width/2+150,visibleSize.height/2));
	this->addChild(sHero1);

    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{

	
	Director::getInstance()->popScene();


}


void GameScene::action(cocos2d::Ref* pSender)
{
	switch (getTag())
	{
		
	case PLAC_TAG : 
		this->sequeueAction(pSender);	
		break;
	case FLYX_TAG :
		this->spawnAction(pSender);
		break;
	case FLYY_TAG :
		this->funcN(pSender);
	//	sHero->runAction(FlipY::create(10.0));
		break;
	default:
		break;
	}
	
	
}

void GameScene::funcN(cocos2d::Ref* pSender)
{
	runAction(CallFuncN::create(CC_CALLBACK_1(GameScene::spawnAction,this)));
//	runAction(CallFuncN::create(CC_CALLBACK_1(GameScene::sequeueAction,this)));
}


void GameScene::onEnter()
{
	Layer::onEnter();
//	log("tag is %d",getTag());
}

void GameScene::spawnAction(cocos2d::Ref* pSender)
{
	GameScene* sp = (GameScene*)pSender;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto randomNubW = cocos2d::random(0,10);
	auto randomNubH = cocos2d::random(0,10);
	auto randomRot = cocos2d::random(0,180);
	
	
	sp->sHero->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	
	sp->sHero->setRotation(0);

	Vec2 randomPoision = Vec2(visibleSize.width*randomNubW/10,visibleSize.height*randomNubH/10);

//	log("Position is (%f,%f)",visibleSize.width*randomNubW/10,visibleSize.height*randomNubH/10);


	FiniteTimeAction* MVto =(FiniteTimeAction*)(MoveTo::create(2.0,randomPoision));
	FiniteTimeAction* ROto =(FiniteTimeAction*)(RotateTo::create(2.0,randomRot));

	sp->sHero->runAction(Spawn::create(MVto,ROto,NULL));
}

void GameScene::sequeueAction(cocos2d::Ref* pSender)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(visibleSize.width/2-200,visibleSize.height/2-100);

	FiniteTimeAction* MVto =(FiniteTimeAction*)(TintBy::create(2.0,100,50,50));

	FiniteTimeAction* rMVto =(FiniteTimeAction*)(MVto->reverse());
//	log("moveto");
	FiniteTimeAction* ROto =(FiniteTimeAction*)(RotateBy::create(2.0,80));
	FiniteTimeAction* rROto =(FiniteTimeAction*)(ROto->reverse());
//	log("rotate");
//	auto sq = Spawn::create(rMVto,rROto,NULL);
	sHero->runAction(Sequence::create(MVto,rMVto,ROto,rROto,NULL));
}