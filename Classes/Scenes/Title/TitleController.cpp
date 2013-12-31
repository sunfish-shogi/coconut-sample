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
		_view->onSelectSceneTransTest([=]() {
			GameManager::getInstance()->emitSelectTransTest();
		});
		_view->onSelectOverlayTest([=]() {
			GameManager::getInstance()->emitSelectOverlayTest();
		});
	}

}
