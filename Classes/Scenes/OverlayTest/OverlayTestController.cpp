//
//  OverlayTestController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "OverlayTestController.h"
#include "OverlayTestView.h"
#include "OverlayTestModel.h"
#include "../../GameManager.h"
#include <coconut/Actions.hpp>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	OverlayTestController::OverlayTestController() {
	}
	
	OverlayTestController::~OverlayTestController() {
	}
	
	void OverlayTestController::init() {
		_view->onSelectBack([]() {
			GameManager::getInstance()->emitSelectBack();
		});
		_view->onSelectNormal([]() {
			GameManager::getInstance()->emitOverlayOpen(nullptr, nullptr);
		});
		_view->onSelectSlideInDown([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::down(0.5f), SlideOut::up(0.5f));
		});
		_view->onSelectSlideInUp([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::up(0.5f), SlideOut::down(0.5f));
		});
		_view->onSelectSlideInLeft([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::left(0.5f), SlideOut::left(0.5f));
		});
		_view->onSelectSlideInRight([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::right(0.5f), SlideOut::right(0.5f));
		});
	}

}
