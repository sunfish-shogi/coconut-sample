//
//  TransTestModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TransTestModule__
#define __coconut_sample__TransTestModule__

#include "TransTestController.h"
#include "TransTestView.h"
#include "TransTestModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class TransTestModule : public coconut::MvcModule {
	public:
		
		TransTestModule() : coconut::MvcModule("TransTest") {}
	
		virtual void addModule() final override {
			add<TransTestModel>();
			add<TransTestView>();
			add<TransTestController>();
		}
		
		virtual void injectModule() final override {
			inject<TransTestView, TransTestModel>(&TransTestView::setModel);
			inject<TransTestController, TransTestModel>(&TransTestController::setModel);
			inject<TransTestController, TransTestView>(&TransTestController::setView);
		}
		
		virtual void prepareModule() final override {
			get<TransTestModel>()->init();
			get<TransTestView>()->init(scene());
			get<TransTestController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__TransTestModule__) */
