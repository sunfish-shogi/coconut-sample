//
//  GestureTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#ifndef __coconut_sample__GestureTestController__
#define __coconut_sample__GestureTestController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class GestureTestView;
	class GestureTestModel;

	class GestureTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(GestureTestView*, _view, View);
		PROPERTY(GestureTestModel*, _model, Model);

	private:

	protected:

	public:

		GestureTestController();
		virtual ~GestureTestController();
		void init();

	};

}

#endif /* defined(__coconut_sample__GestureTestController__) */
