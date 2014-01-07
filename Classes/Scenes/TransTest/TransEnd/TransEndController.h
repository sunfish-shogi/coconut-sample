//
//  TransEndController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#ifndef __coconut_sample__TransEndController__
#define __coconut_sample__TransEndController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TransEndView;
	class TransEndModel;

	class TransEndController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(TransEndView*, _view, View);
		PROPERTY(TransEndModel*, _model, Model);

	private:

	protected:

	public:

		TransEndController();
		virtual ~TransEndController();
		void init();

	};

}

#endif /* defined(__coconut_sample__TransEndController__) */
