#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
//#include "HelloWorldScene.h"
#include "BeganScene.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

	//自适应分辨率 android 
	pEGLView->setDesignResolutionSize(800, 480, kResolutionExactFit);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	SimpleAudioEngine::sharedEngine()->preloadEffect("bgsound.mp3");

    // create a scene. it's an autorelease object
    //CCScene *pScene = HelloWorld::scene();
	CCScene *pScene = BeginSceneLayer::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    //SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() 
{
    CCDirector::sharedDirector()->startAnimation();
    //SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
