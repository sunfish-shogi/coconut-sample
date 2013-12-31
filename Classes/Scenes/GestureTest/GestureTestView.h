//
//  GestureTestView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#ifndef __coconut_sample__GestureTestView__
#define __coconut_sample__GestureTestView__

#include "cocos2d.h"
#include <coconut/Macro.hpp>
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>
#include <coconut/finger_gestures/FingerGesture.h>

namespace coconut_sample {

	class GestureTestModel;

	class GestureTestView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectBack);

		PROPERTY(GestureTestModel*, _model, Model);
		
	private:

		cocos2d::Scene* _scene;
		coconut::FingerGesture _fingerGesture;

	protected:

	public:
		
		GestureTestView();
		virtual ~GestureTestView();
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__GestureTestView__) */
