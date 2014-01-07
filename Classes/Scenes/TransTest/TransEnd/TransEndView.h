//
//  TransEndView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#ifndef __coconut_sample__TransEndView__
#define __coconut_sample__TransEndView__

#include "cocos2d.h"
#include <coconut/Macro.hpp>
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>

namespace coconut_sample {

	class TransEndModel;

	class TransEndView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectBack);

		PROPERTY(TransEndModel*, _model, Model);
		
	private:

		cocos2d::Scene* _scene;

	protected:

	public:
		
		TransEndView();
		virtual ~TransEndView();
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__TransEndView__) */
