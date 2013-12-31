//
//  ScheduleTestView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__ScheduleTestView__
#define __coconut_sample__ScheduleTestView__

#include "cocos2d.h"
#include <coconut/Macro.hpp>
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>
#include <coconut/schedule/ScheduleManager.h>

namespace coconut_sample {

	class ScheduleTestModel;

	class ScheduleTestView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectBack);

		PROPERTY(ScheduleTestModel*, _model, Model);
		PROPERTY(coconut::ScheduleManager*, _scheduleManager, ScheduleManager);
		
	private:

		cocos2d::Scene* _scene;
		
		const coconut::Schedule* _scheduleRotate;
		const coconut::Schedule* _scheduleScale;
		float _scaleCount;

	protected:

	public:
		
		ScheduleTestView();
		virtual ~ScheduleTestView();
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__ScheduleTestView__) */
