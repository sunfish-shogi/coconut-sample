//
//  TransEndModule.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#ifndef __coconut_sample__TransEndModule__
#define __coconut_sample__TransEndModule__

#include "TransEndController.h"
#include "TransEndView.h"
#include "TransEndModel.h"
#include <coconut/MVC.hpp>

namespace coconut_sample {

	class TransEndModule : public coconut::MvcModule {
	public:
		
		TransEndModule() : coconut::MvcModule("TransEnd") {}
	
		virtual void addModule() final override {
			add<TransEndModel>();
			add<TransEndView>();
			add<TransEndController>();
		}
		
		virtual void injectModule() final override {
			inject<TransEndView, TransEndModel>(&TransEndView::setModel);
			inject<TransEndController, TransEndModel>(&TransEndController::setModel);
			inject<TransEndController, TransEndView>(&TransEndController::setView);
		}
		
		virtual void prepareModule() final override {
			get<TransEndModel>()->init();
			get<TransEndView>()->init(scene());
			get<TransEndController>()->init();
		}
		
	};

}

#endif /* defined(__coconut_sample__TransEndModule__) */
