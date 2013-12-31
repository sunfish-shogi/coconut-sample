//
//  NetworkTestModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/07.
//
//

#ifndef __coconut_sample__NetworkTestModule__
#define __coconut_sample__NetworkTestModule__

#include "NetworkTestController.h"
#include "NetworkTestView.h"
#include "NetworkTestModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class NetworkTestModule : public coconut::MvcModule {
	public:
		
		NetworkTestModule() : coconut::MvcModule("NetworkTest") {}
	
		virtual void addModule() final override {
			add<NetworkTestModel>();
			add<NetworkTestView>();
			add<NetworkTestController>();
		}
		
		virtual void injectModule() final override {
			inject<NetworkTestView, NetworkTestModel>(&NetworkTestView::setModel);
			inject<NetworkTestController, NetworkTestModel>(&NetworkTestController::setModel);
			inject<NetworkTestController, NetworkTestView>(&NetworkTestController::setView);
		}
		
		virtual void prepareModule() final override {
			get<NetworkTestModel>()->init();
			get<NetworkTestView>()->init(scene());
			get<NetworkTestController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__NetworkTestModule__) */
