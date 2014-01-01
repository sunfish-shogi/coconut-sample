//
//  SlidePuzzleController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__SlidePuzzleController__
#define __coconut_sample__SlidePuzzleController__

#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class SlidePuzzleView;
	class SlidePuzzleModel;

	class SlidePuzzleController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

	private:

		SlidePuzzleView* _view;
		SlidePuzzleModel* _model;

	protected:

	public:

		SlidePuzzleController();
		virtual ~SlidePuzzleController();
		void setView(SlidePuzzleView* view) {
			_view = view;
		}
		void setModel(SlidePuzzleModel* model) {
			_model = model;
		}
		void init();
		void start();

	};

}

#endif /* defined(__coconut_sample__SlidePuzzleController__) */
