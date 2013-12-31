//
//  TransEndController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#include "TransEndController.h"
#include "TransEndView.h"
#include "TransEndModel.h"
#include "../../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	TransEndController::TransEndController() {
	}
	
	TransEndController::~TransEndController() {
	}
	
	void TransEndController::init() {
		_view->onSelectBack([]() {
			GameManager::getInstance()->emitDoneTransTest();
		});
	}

}
