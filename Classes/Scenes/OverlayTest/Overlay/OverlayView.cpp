//
//  OverlayView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "OverlayView.h"
#include "../../../Utils/WidgetUtils.h"
#include "../../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	OverlayView::OverlayView() {
	}

	OverlayView::~OverlayView() {
	}

	void OverlayView::init(Scene* scene) {
		_scene = scene;
		
		Node* node = Node::create();
		node->setPosition(LayoutUtils::visibleCenter());
		_scene->addChild(node);
		
		Sprite* bg = Sprite::create("Overlay.png");
		bg->setScale(2.0f * ImageUtils::scale4OneSizeImage());
		node->addChild(bg, INT_MIN);
		
		Button* btnClose = WidgetUtils::createTTFButton("Close", "orange", [this]() {
			emitSelectClose();
		});
		btnClose->setPosition(100, 95);
		node->addChild(btnClose, INT_MAX);
	}
	
}
