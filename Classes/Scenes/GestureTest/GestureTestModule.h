//
//  GestureTestModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#ifndef __coconut_sample__GestureTestModule__
#define __coconut_sample__GestureTestModule__

#include "GestureTestController.h"
#include "GestureTestView.h"
#include "GestureTestModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class GestureTestModule : public coconut::MvcModule {
	public:
		
		GestureTestModule() : coconut::MvcModule("GestureTest") {}
	
		virtual void addModule() final override {
			add<GestureTestModel>();
			add<GestureTestView>();
			add<GestureTestController>();
		}
		
		virtual void injectModule() final override {
			inject<GestureTestView, GestureTestModel>(&GestureTestView::setModel);
			inject<GestureTestController, GestureTestModel>(&GestureTestController::setModel);
			inject<GestureTestController, GestureTestView>(&GestureTestController::setView);
		}
		
		virtual void prepareModule() final override {
			get<GestureTestModel>()->init();
			get<GestureTestView>()->init(scene());
			get<GestureTestController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__GestureTestModule__) */
