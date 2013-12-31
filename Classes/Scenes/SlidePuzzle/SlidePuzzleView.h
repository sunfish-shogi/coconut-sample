//
//  SlidePuzzleView.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#ifndef __coconut_sample__SlidePuzzleView__
#define __coconut_sample__SlidePuzzleView__

#include "Array2d/Position.h"
#include "cocos2d.h"
#include <coconut/Macro.hpp>
#include <coconut/EventEmitter.hpp>
#include <coconut/scene/SceneChanger.hpp>
#include <coconut/finger_gestures/FingerGesture.h>

namespace coconut_sample {

	class SlidePuzzleModel;

	class SlidePuzzleView {

		// event emitters
		DEFINE_EVENT_EMITTER(SelectBack);
		DEFINE_EVENT_EMITTER(SelectReset);
		DEFINE_EVENT_EMITTER_WITH_ARG(Touch, const Position&);

		PROPERTY(SlidePuzzleModel*, _model, Model);
		
	private:

		cocos2d::Scene* _scene;
		cocos2d::Texture2D* _piecesTexture;
		cocos2d::SpriteBatchNode* _piecesBatch;
		coconut::FingerGesture _fingerGesture;
		cocos2d::Point _pieceBase;
		
		int getTag(const Position& piece) const;
		cocos2d::Rect getRect(const Position& piece) const;
		cocos2d::Point getPosition(const Position& piece) const;
		
		void reset();
		void slide(const Position& pos);
		void complete();
		
	protected:

	public:
		
		SlidePuzzleView();
		virtual ~SlidePuzzleView();
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__SlidePuzzleView__) */
