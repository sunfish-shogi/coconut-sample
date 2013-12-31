//
//  GestureTestController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#include "GestureTestController.h"
#include "GestureTestView.h"
#include "GestureTestModel.h"
#include "../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	GestureTestController::GestureTestController() {
	}
	
	GestureTestController::~GestureTestController() {
	}
	
	void GestureTestController::init() {
		_view->onSelectBack([]() {
			GameManager::getInstance()->emitSelectBack();
		});
	}

}
