//
//  NetworkTestController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/07.
//
//

#ifndef __coconut_sample__NetworkTestController__
#define __coconut_sample__NetworkTestController__

#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class NetworkTestView;
	class NetworkTestModel;

	class NetworkTestController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

	private:

		NetworkTestView* _view;
		NetworkTestModel* _model;

	protected:

	public:

		NetworkTestController();
		virtual ~NetworkTestController();
		void setView(NetworkTestView* view) {
			_view = view;
		}
		void setModel(NetworkTestModel* model) {
			_model = model;
		}
		void init();

	};

}

#endif /* defined(__coconut_sample__NetworkTestController__) */
