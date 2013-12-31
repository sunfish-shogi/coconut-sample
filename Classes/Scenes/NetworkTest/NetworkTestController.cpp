//
//  NetworkTestController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/07.
//
//

#include "NetworkTestController.h"
#include "NetworkTestView.h"
#include "NetworkTestModel.h"
#include "../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	NetworkTestController::NetworkTestController() {
	}
	
	NetworkTestController::~NetworkTestController() {
	}
	
	void NetworkTestController::init() {
		_view->onSelectBack([]() {
			GameManager::getInstance()->emitSelectBack();
		});
	}

}
