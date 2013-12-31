//
//  GameManager.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/11/29.
//
//

#include "GameManager.h"
#include "Definitions/Resolution.h"
#include "Scenes/Title/TitleModule.h"
#include "Scenes/TransTest/TransTestModule.h"
#include "Scenes/TransTest/TransEnd/TransEndModule.h"
#include "Scenes/OverlayTest/OverlayTestModule.h"
#include "Scenes/OverlayTest/Overlay/OverlayModule.h"
#include <coconut/MVC.hpp>
#include <coconut/Actions.hpp>
#include <coconut/utils/LayoutUtils.h>
#include <coconut/resouces/ImageManager.h>
#include <coconut/resouces/SoundManager.h>
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
using namespace coconut;

namespace coconut_sample {
	
	void GameManager::setup() {
		// close this application
		onClose([=]() {
			Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			exit(0);
#endif
		});
		
		// Any Scene => Title
		onSelectBack([]() {
			MvcBuilder().setMainModule<TitleModule>().prepare(SceneChangers::FlipL(0.5f));
		});
		
		// Title => TransTest
		onSelectTransTest([]() {
			MvcBuilder().setMainModule<TransTestModule>().prepare(SceneChangers::FlipR(0.5f));
		});
		
		// TransTest
		onDoTransTest([](const SceneChanger& sceneChanger) {
			MvcBuilder().setMainModule<TransEndModule>().prepare(sceneChanger);
		});
		onDoneTransTest([]() {
			SceneRestorers::StackedScene().pop();
		});
		
		// Title => OverlayTest
		onSelectOverlayTest([]() {
			MvcBuilder().setMainModule<OverlayTestModule>().prepare(SceneChangers::FlipR(0.5f));
		});
		
		// Show Overlay
		onOverlayOpen([this](Action* openAction, Action* closeAction) {
			if (openAction) {
				MvcBuilder().setMainModule<OverlayModule>().prepare(SceneChangers::Overlay((FiniteTimeAction*)openAction));
			} else {
				MvcBuilder().setMainModule<OverlayModule>().prepare(SceneChangers::Overlay());
			}
			if (closeAction) {
				closeAction->retain();
			}
			_actionStack.push(closeAction);
		});
		
		// Close Overlay
		onOverlayClose([this]() {
			FiniteTimeAction* action = (FiniteTimeAction*)_actionStack.top();
			if (action != nullptr) {
				SceneRestorers::Overlay(action).close();
				action->release();
			} else {
				SceneRestorers::Overlay().close();
			}
		});
	}
	
	void GameManager::initDisplay() {
		// initialize director
		auto director = Director::getInstance();
		auto eglView = EGLView::getInstance();
		director->setOpenGLView(eglView);
		
		const Size& frameSize = eglView->getFrameSize();
		float contentScale;
		std::vector<std::string> searchPath;
		
		searchPath.push_back("images/common");
		searchPath.push_back("images_dev/common");
		if (frameSize.height > 1536) {
			// iPad Retina
			contentScale = CONTENT_SCALE_LARGE;
			searchPath.push_back("images/large");
		} else if (frameSize.height > 768) {
			// iPhone Retina, iPad
			contentScale = CONTENT_SCALE_NORMAL;
			searchPath.push_back("images/normal");
		} else {
			// iPhone
			contentScale = CONTENT_SCALE_SMALL;
			searchPath.push_back("images/small");
		}
		
		// content scale
		director->setContentScaleFactor(contentScale);
		
		// search path
		FileUtils::getInstance()->setSearchPaths(searchPath);
		
		// design resolution
		const Size& size = Director::getInstance()->getVisibleSize();
		float width = DESIGN_RESOL_WIDTH(size.width / contentScale);
		float height = size.height * width / size.width;
		eglView->setDesignResolutionSize(width, height, ResolutionPolicy::SHOW_ALL);
		
		log("[frame] %f, %f", frameSize.width, frameSize.height);
		log("[content scale] %f", contentScale);
		log("[design resolution] %f, %f", width, height);
		
		// images
		ImageManager* imageManager = ImageManager::getInstance();
		imageManager->addCommonSpriteFrame("ui.plist");
		imageManager->prepare();
		
		// sounds
		SoundManager* soundManager = SoundManager::getInstance();
		soundManager->prepare();
		
		// turn on display FPS
		director->setDisplayStats(true);
		
		// set FPS. the default value is 1.0/60 if you don't call this
		director->setAnimationInterval(1.0 / 60);
	}
	
	void GameManager::startGame() {
		MvcBuilder().setMainModule<TitleModule>().prepare(SceneChangers::Initial());
	}
	
}
