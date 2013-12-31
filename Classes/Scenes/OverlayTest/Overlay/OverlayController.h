//
//  OverlayController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__OverlayController__
#define __coconut_sample__OverlayController__

#include <coconut/Macro.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class OverlayView;
	class OverlayModel;

	class OverlayController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

		PROPERTY(OverlayView*, _view, View);
		PROPERTY(OverlayModel*, _model, Model);

	private:

	protected:

	public:

		OverlayController();
		virtual ~OverlayController();
		void init();

	};

}

#endif /* defined(__coconut_sample__OverlayController__) */
