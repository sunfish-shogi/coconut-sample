//
//  TitleController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "TitleController.h"
#include "TitleView.h"
#include "TitleModel.h"
#include "../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	TitleController::TitleController() {
	}
	
	TitleController::~TitleController() {
	}
	
	void TitleController::init() {
		_view->onSelectClose([=]() {
			GameManager::getInstance()->emitClose();
		});
		_view->onSelectSlidePuzzle([=]() {
			GameManager::getInstance()->emitSelectSlidePuzzle();
		});
		_view->onSelectSceneTransTest([=]() {
			GameManager::getInstance()->emitSelectTransTest();
		});
		_view->onSelectOverlayTest([=]() {
			GameManager::getInstance()->emitSelectOverlayTest();
		});
		_view->onSelectGestureTest([=]() {
			GameManager::getInstance()->emitSelectGestureTest();
		});
		_view->onSelectScheduleTest([=]() {
			GameManager::getInstance()->emitSelectScheduleTest();
		});
		_view->onSelectNetworkTest([=]() {
			GameManager::getInstance()->emitSelectNetworkTest();
		});
	}

}
