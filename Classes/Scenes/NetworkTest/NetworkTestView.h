//
//  NetworkTestView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/07.
//
//

#ifndef __coconut_sample__NetworkTestView__
#define __coconut_sample__NetworkTestView__

#include "cocos2d.h"
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>
#include <coconut/network/HttpManager.h>

namespace coconut_sample {

	class NetworkTestModel;

	class NetworkTestView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectBack);

	private:

		NetworkTestModel* _model;
		cocos2d::Scene* _scene;
		coconut::HttpManager _http;
		
		void get();

	protected:

	public:
		
		NetworkTestView();
		virtual ~NetworkTestView();
		void setModel(NetworkTestModel* model) {
			_model = model;
		}
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__NetworkTestView__) */
