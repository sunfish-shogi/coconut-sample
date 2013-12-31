//
//  TransTestController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "TransTestController.h"
#include "TransTestView.h"
#include "TransTestModel.h"
#include "../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	TransTestController::TransTestController() {
	}
	
	TransTestController::~TransTestController() {
	}
	
	void TransTestController::init() {
		_view->onSelectBack([]() {
			GameManager::getInstance()->emitSelectBack();
		});
		_view->onSelectTrans([](const SceneChanger& sceneChanger) {
			GameManager::getInstance()->emitDoTransTest(sceneChanger);
		});
	}

}
