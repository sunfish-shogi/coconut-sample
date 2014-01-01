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

	private:

		SlidePuzzleModel* _model;
		cocos2d::Scene* _scene;
		cocos2d::Texture2D* _piecesTexture;
		cocos2d::SpriteBatchNode* _piecesBatch;
		
		cocos2d::Point _pieceBase;
		int getTag(const Position& piece) const;
		cocos2d::Rect getRect(const Position& piece) const;
		cocos2d::Point getPosition(const Position& piece) const;
		
		coconut::FingerGesture _fingerGesture;
		
		void reset();
		void set(const Position& pos);
		void slide(const Position& pos);
		void complete();
		
	protected:

	public:
		
		SlidePuzzleView();
		virtual ~SlidePuzzleView();
		void setModel(SlidePuzzleModel* model) {
			_model = model;
		}
		void init(cocos2d::Scene* scene);
		
	};

}

#endif /* defined(__coconut_sample__SlidePuzzleView__) */
