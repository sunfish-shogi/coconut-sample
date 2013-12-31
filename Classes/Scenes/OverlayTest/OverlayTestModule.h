//
//  OverlayTestModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__OverlayTestModule__
#define __coconut_sample__OverlayTestModule__

#include "OverlayTestController.h"
#include "OverlayTestView.h"
#include "OverlayTestModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class OverlayTestModule : public coconut::MvcModule {
	public:
		
		OverlayTestModule() : coconut::MvcModule("OverlayTest") {}
	
		virtual void addModule() final override {
			add<OverlayTestModel>();
			add<OverlayTestView>();
			add<OverlayTestController>();
		}
		
		virtual void injectModule() final override {
			inject<OverlayTestView, OverlayTestModel>(&OverlayTestView::setModel);
			inject<OverlayTestController, OverlayTestModel>(&OverlayTestController::setModel);
			inject<OverlayTestController, OverlayTestView>(&OverlayTestController::setView);
		}
		
		virtual void prepareModule() final override {
			get<OverlayTestModel>()->init();
			get<OverlayTestView>()->init(scene());
			get<OverlayTestController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__OverlayTestModule__) */
