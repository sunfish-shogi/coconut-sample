//
//  TitleModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TitleModule__
#define __coconut_sample__TitleModule__

#include "TitleController.h"
#include "TitleView.h"
#include "TitleModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class TitleModule : public coconut::MvcModule {
	public:
		
		TitleModule() : coconut::MvcModule("Title") {}
	
		virtual void addModule() final override {
			add<TitleModel>();
			add<TitleView>();
			add<TitleController>();
		}
		
		virtual void injectModule() final override {
			inject<TitleView, TitleModel>(&TitleView::setModel);
			inject<TitleController, TitleModel>(&TitleController::setModel);
			inject<TitleController, TitleView>(&TitleController::setView);
		}
		
		virtual void prepareModule() final override {
			get<TitleModel>()->init();
			get<TitleView>()->init(scene());
			get<TitleController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__TitleModule__) */
