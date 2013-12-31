//
//  TitleController.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TitleController__
#define __coconut_sample__TitleController__

#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TitleView;
	class TitleModel;

	class TitleController {

		// event emitters
//		DEFINE_EVENT_EMITTER(/* event name */);

	private:

		TitleView* _view;
		TitleModel* _model;

	protected:

	public:

		TitleController();
		virtual ~TitleController();
		void setView(TitleView* view) {
			_view = view;
		}
		void setModel(TitleModel* model) {
			_model = model;
		}
		void init();

	};

}

#endif /* defined(__coconut_sample__TitleController__) */
