//
//  OverlayController.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "OverlayController.h"
#include "OverlayView.h"
#include "OverlayModel.h"
#include "../../../GameManager.h"

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	OverlayController::OverlayController() {
	}
	
	OverlayController::~OverlayController() {
	}
	
	void OverlayController::init() {
		_view->onSelectClose([]() {
			GameManager::getInstance()->emitOverlayClose();
		});
	}

}
