//
//  GestureTestView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#include "GestureTestView.h"
#include "../../Utils/WidgetUtils.h"
#include "../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	GestureTestView::GestureTestView() {
	}

	GestureTestView::~GestureTestView() {
	}

	void GestureTestView::init(Scene* scene) {
		_scene = scene;
		
		Node* node = Node::create();
		node->setPosition(LayoutUtils::visibleCenter() - Point(240, 160));
		_scene->addChild(node);
		
		// background
		Point bgPos(240, 160);
		float bgScale = 2.0f * ImageUtils::scale4OneSizeImage();
		Sprite* bg = Sprite::create("bg.png");
		bg->setScale(bgScale);
		bg->setPosition(bgPos);
		node->addChild(bg, INT_MIN);
		
		// back button
		Button* btnBack = WidgetUtils::createTTFButton("Back", "orange", [this]() {
			emitSelectBack();
		});
		btnBack->setPosition(Point(430, 295));
		node->addChild(btnBack, INT_MAX);
		
		// reset button
		Button* btnReset = WidgetUtils::createTTFButton("Reset", [=]() {
			bg->setPosition(bgPos);
			bg->setScale(bgScale);
			bg->setRotation(0.0f);
		});
		btnReset->setPosition(Point(50, 295));
		node->addChild(btnReset, INT_MAX);
		
		// finger gesture
		_fingerGesture.fgMoveWithDeltaRotation = [=](const Point& pos, const Point& delta, double rotate) {
			float rad = rotate * (M_PI / 180.0f);
			Point from = bg->getPosition() - pos;
			Point to(from.x * cosf(rad) + from.y * sinf(rad),
							 -from.x * sinf(rad) + from.y * cosf(rad));
			bg->setPosition(bg->getPosition() + delta + to - from);
			bg->setRotation(bg->getRotation() + rotate);
			return GestureResult::Ok;
		};
		_fingerGesture.fgPinch = [=](const Point& center, float scale) {
			Point pos = center + (bg->getPosition() - center) * scale;
			bg->setPosition(pos);
			bg->setScale(bg->getScale() * scale);
			return GestureResult::Ok;
		};
		_fingerGesture.registerWithNode(node, true);
	}
	
}
