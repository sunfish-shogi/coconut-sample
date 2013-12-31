//
//  ScheduleTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__ScheduleTestController__
#define __coconut_sample__ScheduleTestController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class ScheduleTestView;
	class ScheduleTestModel;

	class ScheduleTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(ScheduleTestView*, _view, View);
		PROPERTY(ScheduleTestModel*, _model, Model);

	private:

	protected:

	public:

		ScheduleTestController();
		virtual ~ScheduleTestController();
		void init();

	};

}

#endif /* defined(__coconut_sample__ScheduleTestController__) */
