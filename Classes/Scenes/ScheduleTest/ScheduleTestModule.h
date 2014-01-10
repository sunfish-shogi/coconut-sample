//
//  ScheduleTestModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__ScheduleTestModule__
#define __coconut_sample__ScheduleTestModule__

#include "ScheduleTestController.h"
#include "ScheduleTestView.h"
#include "ScheduleTestModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class ScheduleTestModule : public coconut::MvcModule {
	public:
		
		ScheduleTestModule() : coconut::MvcModule("ScheduleTest") {}
	
		virtual void addModule() final override {
			add<ScheduleTestModel>();
			add<ScheduleTestView>();
			add<ScheduleTestController>();
		}
		
		virtual void injectModule() final override {
			inject<ScheduleTestView, ScheduleTestModel>(&ScheduleTestView::setModel);
			inject<ScheduleTestController, ScheduleTestModel>(&ScheduleTestController::setModel);
			inject<ScheduleTestController, ScheduleTestView>(&ScheduleTestController::setView);
			
			inject<ScheduleTestView, coconut::ScheduleManager>(&ScheduleTestView::setScheduleManager);
		}
		
		virtual void prepareModule() final override {
			get<ScheduleTestModel>()->init();
			get<ScheduleTestView>()->init(scene());
			get<ScheduleTestController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__ScheduleTestModule__) */
