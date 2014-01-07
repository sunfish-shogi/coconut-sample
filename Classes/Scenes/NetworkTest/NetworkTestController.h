//
//  NetworkTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/07.
//
//

#ifndef __coconut_sample__NetworkTestController__
#define __coconut_sample__NetworkTestController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class NetworkTestView;
	class NetworkTestModel;

	class NetworkTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(NetworkTestView*, _view, View);
		PROPERTY(NetworkTestModel*, _model, Model);

	private:

	protected:

	public:

		NetworkTestController();
		virtual ~NetworkTestController();
		void init();

	};

}

#endif /* defined(__coconut_sample__NetworkTestController__) */
