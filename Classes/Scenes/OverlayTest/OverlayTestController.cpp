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
		_view->onSelectSlideInTop([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::top(0.5f), SlideOut::top(0.5f));
		});
		_view->onSelectSlideInBottom([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::bottom(0.5f), SlideOut::bottom(0.5f));
		});
		_view->onSelectSlideInLeft([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::left(0.5f), SlideOut::left(0.5f));
		});
		_view->onSelectSlideInRight([]() {
			GameManager::getInstance()->emitOverlayOpen(SlideIn::right(0.5f), SlideOut::right(0.5f));
		});
	}

}
