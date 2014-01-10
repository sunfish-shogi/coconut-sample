//
//  SlidePuzzleModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__SlidePuzzleModule__
#define __coconut_sample__SlidePuzzleModule__

#include "SlidePuzzleController.h"
#include "SlidePuzzleView.h"
#include "SlidePuzzleModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class SlidePuzzleModule : public coconut::MvcModule {
	public:
		
		SlidePuzzleModule() : coconut::MvcModule("SlidePuzzle") {}
	
		virtual void addModule() final override {
			add<SlidePuzzleModel>();
			add<SlidePuzzleView>();
			add<SlidePuzzleController>();
		}
		
		virtual void injectModule() final override {
			inject<SlidePuzzleView, SlidePuzzleModel>(&SlidePuzzleView::setModel);
			inject<SlidePuzzleController, SlidePuzzleModel>(&SlidePuzzleController::setModel);
			inject<SlidePuzzleController, SlidePuzzleView>(&SlidePuzzleController::setView);
			
			inject<SlidePuzzleModel, coconut::ScheduleManager>(&SlidePuzzleModel::setScheduleManager);
		}
		
		virtual void prepareModule() final override {
			get<SlidePuzzleModel>()->init();
			get<SlidePuzzleView>()->init(scene());
			get<SlidePuzzleController>()->init();
			SlidePuzzleController* controller = get<SlidePuzzleController>();
			onEnterTransFinish([=]() {
				controller->start();
			});
		}
		
	};

}

#endif /* defined(__coconut_sample__SlidePuzzleModule__) */
