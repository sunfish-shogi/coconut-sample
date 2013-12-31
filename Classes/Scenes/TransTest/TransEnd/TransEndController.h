//
//  TransEndController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#ifndef __coconut_sample__TransEndController__
#define __coconut_sample__TransEndController__

#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TransEndView;
	class TransEndModel;

	class TransEndController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

	private:

		TransEndView* _view;
		TransEndModel* _model;

	protected:

	public:

		TransEndController();
		virtual ~TransEndController();
		void setView(TransEndView* view) {
			_view = view;
		}
		void setModel(TransEndModel* model) {
			_model = model;
		}
		void init();

	};

}

#endif /* defined(__coconut_sample__TransEndController__) */
