//
//  OverlayModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__OverlayModule__
#define __coconut_sample__OverlayModule__

#include "OverlayController.h"
#include "OverlayView.h"
#include "OverlayModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class OverlayModule : public coconut::MvcModule {
	public:
		
		OverlayModule() : coconut::MvcModule("Overlay") {}
	
		virtual void addModule() final override {
			add<OverlayModel>();
			add<OverlayView>();
			add<OverlayController>();
		}
		
		virtual void injectModule() final override {
			inject<OverlayView, OverlayModel>(&OverlayView::setModel);
			inject<OverlayController, OverlayModel>(&OverlayController::setModel);
			inject<OverlayController, OverlayView>(&OverlayController::setView);
		}
		
		virtual void prepareModule() final override {
			get<OverlayModel>()->init();
			get<OverlayView>()->init(scene());
			get<OverlayController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__OverlayModule__) */
