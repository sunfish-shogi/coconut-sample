//
//  OverlayView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__OverlayView__
#define __coconut_sample__OverlayView__

#include "cocos2d.h"
#include <coconut/Macro.hpp>
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class OverlayModel;

	class OverlayView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectClose);

		PROPERTY(OverlayModel*, _model, Model);
		
	private:

		cocos2d::Scene* _scene;

	protected:

	public:
		
		OverlayView();
		virtual ~OverlayView();
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__OverlayView__) */
