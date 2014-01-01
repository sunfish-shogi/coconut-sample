//
//  ScheduleTestController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#include "ScheduleTestController.h"
#include "ScheduleTestView.h"
#include "ScheduleTestModel.h"
#include "../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	ScheduleTestController::ScheduleTestController() {
	}
	
	ScheduleTestController::~ScheduleTestController() {
	}
	
	void ScheduleTestController::init() {
		_view->onSelectBack([]() {
			GameManager::getInstance()->emitSelectBack();
		});
	}

}
