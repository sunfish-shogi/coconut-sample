//
//  ScheduleTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__ScheduleTestController__
#define __coconut_sample__ScheduleTestController__

#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class ScheduleTestView;
	class ScheduleTestModel;

	class ScheduleTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

	private:

		ScheduleTestView* _view;
		ScheduleTestModel* _model;

	protected:

	public:

		ScheduleTestController();
		virtual ~ScheduleTestController();
		void setView(ScheduleTestView* view) {
			_view = view;
		}
		void setModel(ScheduleTestModel* model) {
			_model = model;
		}
		void init();

	};

}

#endif /* defined(__coconut_sample__ScheduleTestController__) */
