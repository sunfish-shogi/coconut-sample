//
//  TransTestView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#ifndef __coconut_sample__TransTestView__
#define __coconut_sample__TransTestView__

#include "cocos2d.h"
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>
#include <coconut/widgets/tile_view/SimpleTileView.h>

namespace coconut_sample {

	class TransTestModel;

	class TransTestView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectBack);
		DEFINE_EVENT_EMITTER_WITH_ARG(SelectTrans, const coconut::SceneChanger&);

	private:

		TransTestModel* _model;
		cocos2d::Scene* _scene;
		
	protected:

	public:
		
		TransTestView();
		virtual ~TransTestView();
		void setModel(TransTestModel* model) {
			_model = model;
		}
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__TransTestView__) */
