//
//  TransEndView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/31.
//
//

#include "TransEndView.h"
#include "../../../Utils/WidgetUtils.h"
#include "../../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	TransEndView::TransEndView() {
	}

	TransEndView::~TransEndView() {
	}

	void TransEndView::init(Scene* scene) {
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
		btnBack->setPosition(Point(240, 160));
		node->addChild(btnBack, INT_MAX);
	}
	
}
