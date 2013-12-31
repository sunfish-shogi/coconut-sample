//
//  GameManager.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/11/29.
//
//

#ifndef __coconut_sample__GameManager__
#define __coconut_sample__GameManager__

#include <coconut/ObjectContainer.hpp>
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>
#include "cocos2d.h"
#include <stack>

namespace coconut_sample {
	
	class GameManager {
		
		DEFINE_EVENT_EMITTER(Close);
		DEFINE_EVENT_EMITTER(SelectBack);
		
		DEFINE_EVENT_EMITTER(SelectTransTest);
		DEFINE_EVENT_EMITTER_WITH_ARG(DoTransTest, const coconut::SceneChanger&);
		DEFINE_EVENT_EMITTER(DoneTransTest);
		
		DEFINE_EVENT_EMITTER(SelectOverlayTest);
		DEFINE_EVENT_EMITTER_WITH_ARGS2(OverlayOpen, cocos2d::Action*, cocos2d::Action*);
		DEFINE_EVENT_EMITTER(OverlayClose);
	
	private:
		
		std::stack<cocos2d::Action*> _actionStack;
		
		GameManager() {
		}
		~GameManager() {
		}
		
	public:
		
		static GameManager* getInstance() {
			static GameManager instance;
			return &instance;
		}
		
		void setup();
		
		void initDisplay();
		
		void startGame();
		
	};
	
}

#endif /* defined(__coconut_sample__GameManager__) */
