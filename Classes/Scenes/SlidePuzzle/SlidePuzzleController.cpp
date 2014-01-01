//
//  SlidePuzzleController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#include "SlidePuzzleController.h"
#include "SlidePuzzleView.h"
#include "SlidePuzzleModel.h"
#include "../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	SlidePuzzleController::SlidePuzzleController() {
	}
	
	SlidePuzzleController::~SlidePuzzleController() {
	}
	
	void SlidePuzzleController::init() {
		_view->onSelectBack([]() {
			GameManager::getInstance()->emitSelectBack();
		});
		_view->onSelectReset([this]() {
			_model->reset();
		});
		_view->onTouch([this](const Position& pos) {
			_model->slide(pos);
		});
	}
	
	void SlidePuzzleController::start() {
		_model->reset();
	}

}
