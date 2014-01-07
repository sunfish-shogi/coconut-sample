//
//  TransTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TransTestController__
#define __coconut_sample__TransTestController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TransTestView;
	class TransTestModel;

	class TransTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(TransTestView*, _view, View);
		PROPERTY(TransTestModel*, _model, Model);

	private:

	protected:

	public:

		TransTestController();
		virtual ~TransTestController();
		void init();

	};

}

#endif /* defined(__coconut_sample__TransTestController__) */
