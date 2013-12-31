//
//  TitleController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TitleController__
#define __coconut_sample__TitleController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TitleView;
	class TitleModel;

	class TitleController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(TitleView*, _view, View);
		PROPERTY(TitleModel*, _model, Model);

	private:

	protected:

	public:

		TitleController();
		virtual ~TitleController();
		void init();

	};

}

#endif /* defined(__coconut_sample__TitleController__) */
