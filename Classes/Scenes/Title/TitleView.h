//
//  TitleView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TitleView__
#define __coconut_sample__TitleView__

#include "cocos2d.h"
#include <coconut/Macro.hpp>
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TitleModel;

	class TitleView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectClose);
		DEFINE_EVENT_EMITTER(SelectSlidePuzzle);
		DEFINE_EVENT_EMITTER(SelectSceneTransTest);
		DEFINE_EVENT_EMITTER(SelectOverlayTest);
		DEFINE_EVENT_EMITTER(SelectGestureTest);
		DEFINE_EVENT_EMITTER(SelectScheduleTest);
		DEFINE_EVENT_EMITTER(SelectNetworkTest);

		PROPERTY(TitleModel*, _model, Model);
		
	private:

		cocos2d::Scene* _scene;

	protected:

	public:
		
		TitleView();
		virtual ~TitleView();
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__TitleView__) */
