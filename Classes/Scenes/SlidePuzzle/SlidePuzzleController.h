//
//  SlidePuzzleController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__SlidePuzzleController__
#define __coconut_sample__SlidePuzzleController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class SlidePuzzleView;
	class SlidePuzzleModel;

	class SlidePuzzleController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(SlidePuzzleView*, _view, View);
		PROPERTY(SlidePuzzleModel*, _model, Model);

	private:

	protected:

	public:

		SlidePuzzleController();
		virtual ~SlidePuzzleController();
		void init();
		void start();

	};

}

#endif /* defined(__coconut_sample__SlidePuzzleController__) */
