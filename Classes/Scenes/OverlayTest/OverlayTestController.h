//
//  OverlayTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__OverlayTestController__
#define __coconut_sample__OverlayTestController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class OverlayTestView;
	class OverlayTestModel;

	class OverlayTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(OverlayTestView*, _view, View);
		PROPERTY(OverlayTestModel*, _model, Model);

	private:

	protected:

	public:

		OverlayTestController();
		virtual ~OverlayTestController();
		void init();

	};

}

#endif /* defined(__coconut_sample__OverlayTestController__) */
