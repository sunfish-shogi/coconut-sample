//
//  OverlayTestView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__OverlayTestView__
#define __coconut_sample__OverlayTestView__

#include "cocos2d.h"
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class OverlayTestModel;

	class OverlayTestView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectBack);
		DEFINE_EVENT_EMITTER(SelectNormal);
		DEFINE_EVENT_EMITTER(SelectSlideInDown);
		DEFINE_EVENT_EMITTER(SelectSlideInUp);
		DEFINE_EVENT_EMITTER(SelectSlideInLeft);
		DEFINE_EVENT_EMITTER(SelectSlideInRight);

	private:

		OverlayTestModel* _model;
		cocos2d::Scene* _scene;

	protected:

	public:
		
		OverlayTestView();
		virtual ~OverlayTestView();
		void setModel(OverlayTestModel* model) {
			_model = model;
		}
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__OverlayTestView__) */
