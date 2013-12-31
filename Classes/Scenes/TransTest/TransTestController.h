//
//  TransTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TransTestController__
#define __coconut_sample__TransTestController__

#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TransTestView;
	class TransTestModel;

	class TransTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

	private:

		TransTestView* _view;
		TransTestModel* _model;

	protected:

	public:

		TransTestController();
		virtual ~TransTestController();
		void setView(TransTestView* view) {
			_view = view;
		}
		void setModel(TransTestModel* model) {
			_model = model;
		}
		void init();

	};

}

#endif /* defined(__coconut_sample__TransTestController__) */
