//
//  OverlayTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__OverlayTestController__
#define __coconut_sample__OverlayTestController__

#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class OverlayTestView;
	class OverlayTestModel;

	class OverlayTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

	private:

		OverlayTestView* _view;
		OverlayTestModel* _model;

	protected:

	public:

		OverlayTestController();
		virtual ~OverlayTestController();
		void setView(OverlayTestView* view) {
			_view = view;
		}
		void setModel(OverlayTestModel* model) {
			_model = model;
		}
		void init();

	};

}

#endif /* defined(__coconut_sample__OverlayTestController__) */
