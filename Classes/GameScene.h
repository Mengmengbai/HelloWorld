#pragma once
#include "cocos2d.h"
#include "HelloWorldScene.h"

class GameScene : public cocos2d::Layer
{
public:
	 bool flag ;

	cocos2d::Sprite* sHero;
	    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	virtual void onEnter();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	//an action
	void action(cocos2d::Ref* pSender);

	void spawnAction(cocos2d::Ref* pSender);

	void sequeueAction(cocos2d::Ref* pSender);

	void funcN(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
	CREATE_FUNC(GameScene);
	
};

