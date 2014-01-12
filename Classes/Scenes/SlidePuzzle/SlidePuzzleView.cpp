//
//  SlidePuzzleView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#include "SlidePuzzleView.h"
#include "SlidePuzzleModel.h"
#include "SlidePuzzle.h"
#include "../../Utils/WidgetUtils.h"
#include "../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>
#include <coconut/Actions.hpp>

USING_NS_CC;
using namespace coconut;

#define IMAGE_WIDTH								240.0f
#define IMAGE_HEIGHT							240.0f

namespace coconut_sample {

	SlidePuzzleView::SlidePuzzleView() {
		_piecesTexture = nullptr;
	}

	SlidePuzzleView::~SlidePuzzleView() {
		if (_piecesTexture) {
		}
	}

	/**********************************************************
	 * initialization                                         *
	 **********************************************************/
	void SlidePuzzleView::init(Scene* scene) {
		_scene = scene;
		
		Node* node = Node::create();
		node->setPosition(LayoutUtils::visibleCenter() - Point(240, 160));
		_scene->addChild(node);
		
		// background
		Sprite* bg = Sprite::create("bg.png");
		bg->setScale(2.0f * ImageUtils::scale4OneSizeImage());
		bg->setPosition(Point(240, 160));
		node->addChild(bg, INT_MIN);
		
		// back button
		Button* btnBack = WidgetUtils::createTTFButton("Back", "orange", [this]() {
			emitSelectBack();
		});
		btnBack->setPosition(Point(430, 295));
		node->addChild(btnBack, INT_MAX);
		
		// reset button
		Button* btnReset = WidgetUtils::createTTFButton("Reset", [this]() {
			emitSelectReset();
		});
		btnReset->setPosition(Point(50, 295));
		node->addChild(btnReset, INT_MAX);
		
		// batch node
		_piecesTexture = Director::getInstance()->getTextureCache()->getTextureForKey("Puzzle.png");
		_piecesBatch = SpriteBatchNode::createWithTexture(_piecesTexture);
		_piecesBatch->setPosition(Point(240, 160));
		node->addChild(_piecesBatch);
		
		_pieceBase = -Point(IMAGE_WIDTH, IMAGE_HEIGHT) * 0.5f;
		
		// touch events
		_fingerGesture.fgTouchFilter = [this](const Point& point) {
			Rect rect(_pieceBase.x, _pieceBase.y, IMAGE_WIDTH, IMAGE_HEIGHT);
			return rect.containsPoint(point) ? TouchFilterResult::Ok : TouchFilterResult::Reject;
		};
		_fingerGesture.fgTouch = [this](const Point& point) {
			float width = IMAGE_WIDTH / _model->getWidth();
			float height = IMAGE_HEIGHT / _model->getHeight();
			Point p = point - _pieceBase;
			Position pos(p.x / width, p.y / height);
			emitTouch(pos);
			return GestureResult::Ok;
		};
		_fingerGesture.registerWithNode(_piecesBatch);
		
		// event handlers
		_model->onReset([this]() {
			reset();
		});
		_model->onSlide([this](const Position& pos) {
			slide(pos);
		});
		_model->onComplete([this]() {
			complete();
		});
	}
	
	/**********************************************************
	 * functions                                              *
	 **********************************************************/
	int SlidePuzzleView::getTag(const Position& piece) const {
		return piece.x + piece.y * _model->getWidth();
	}
	
	Rect SlidePuzzleView::getRect(const Position& piece) const {
		float scale = 2.0f * ImageUtils::scale4OneSizeImage();
		float width = IMAGE_WIDTH / _model->getWidth();
		float height = IMAGE_HEIGHT / _model->getHeight();
		return Rect((piece.x * width + 2.0f) / scale,
								(IMAGE_HEIGHT - (piece.y+1) * height + 2.0f) / scale,
								(width - 4.0f) / scale,
								(height - 4.0f) / scale);
	}
	
	Point SlidePuzzleView::getPosition(const Position& piece) const {
		float width = IMAGE_WIDTH / _model->getWidth();
		float height = IMAGE_WIDTH / _model->getHeight();
		Point offset = Point(width, height) * 0.5f;
		return _pieceBase + offset + Point(piece.x * width, piece.y * height);
	}
	
	/**********************************************************
	 * event handlers                                         *
	 **********************************************************/
	void SlidePuzzleView::reset() {
		_piecesBatch->removeAllChildrenWithCleanup(true);
		for (int x = 0; x < _model->getWidth(); x++) {
			for (int y = 0; y < _model->getHeight(); y++) {
				Position pos(x, y);
				Position piece = _model->getPieces().get(pos);
				if (!IS_EMPTY(piece)) {
					int tag = getTag(piece);
					Rect rect = getRect(piece);
					Sprite* sprite = Sprite::createWithTexture(_piecesTexture, rect);
					sprite->setScale(2.0f * ImageUtils::scale4OneSizeImage());
					sprite->setPosition(getPosition(piece));
					_piecesBatch->addChild(sprite, 0, tag);
				}
			}
		}
	}
	
	void SlidePuzzleView::slide(const Position& pos) {
		Position piece = _model->getPieces().get(pos);
		int tag = getTag(piece);
		Sprite* sprite = (Sprite*)_piecesBatch->getChildByTag(tag);
		CCASSERT(sprite, "sprite not found.");
		sprite->runAction(MoveTo::create(TIME_SLIDE, getPosition(pos)));
	}
	
	void SlidePuzzleView::complete() {
		_piecesBatch->removeAllChildrenWithCleanup(true);
		Sprite* sprite = Sprite::createWithTexture(_piecesTexture);
		sprite->setScale(2.0f * ImageUtils::scale4OneSizeImage());
		sprite->setPosition(Point(0, 0));
		_piecesBatch->addChild(sprite, 0);
		sprite->runAction(Sequence::createWithTwoActions(DelayTime::create(0.5f),
																										 Spawn::createWithTwoActions(RotateBy::create(1.0f, 360.0f * 2),
																																								 Sequence::createWithTwoActions(ScaleBy::create(0.5f, 2.0f),
																																																								ScaleBy::create(0.5f, 0.5f)))));
	}

}
