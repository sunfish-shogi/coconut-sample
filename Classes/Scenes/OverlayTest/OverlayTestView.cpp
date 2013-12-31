//
//  OverlayTestView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "OverlayTestView.h"
#include "../../Utils/WidgetUtils.h"
#include "../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>
#include <coconut/widgets/list_view/SimpleListView.h>
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	OverlayTestView::OverlayTestView() {
	}

	OverlayTestView::~OverlayTestView() {
	}

	void OverlayTestView::init(Scene* scene) {
		_scene = scene;
		
		Node* node = Node::create();
		node->setPosition(LayoutUtils::visibleCenter() - Point(160, 240));
		_scene->addChild(node);
		
		// background
		Sprite* bg = Sprite::create("bg.png");
		bg->setScale(2.0f * ImageUtils::scale4OneSizeImage());
		bg->setPosition(Point(160, 240));
		node->addChild(bg, INT_MIN);
		
		// back button
		Button* btnBack = WidgetUtils::createTTFButton("Back", "orange", [this]() {
			emitSelectBack();
		});
		btnBack->setPosition(Point(270, 455));
		node->addChild(btnBack, INT_MAX);
		
		// list view
		const Size vsize(300, 410);
		const Size esize(300, 42);
		SimpleListView* list = SimpleListView::create(ListDirection::VERTICAL, vsize);
		
		// normal
		Button* btnNormal = WidgetUtils::createTTFButton("Normal", [this]() {
			emitSelectNormal();
		});
		list->addElement(btnNormal, esize);
		
		// slide in (down)
		Button* btnDown = WidgetUtils::createTTFButton("Slide In Down", [this]() {
			emitSelectSlideInDown();
		});
		list->addElement(btnDown, esize);
		
		// slide in (up)
		Button* btnUp = WidgetUtils::createTTFButton("Slide In Up", [this]() {
			emitSelectSlideInUp();
		});
		list->addElement(btnUp, esize);
		
		// slide in (left)
		Button* btnLeft = WidgetUtils::createTTFButton("Slide In Left", [this]() {
			emitSelectSlideInLeft();
		});
		list->addElement(btnLeft, esize);
		
		// slide in (right)
		Button* btnRight = WidgetUtils::createTTFButton("Slide In Right", [this]() {
			emitSelectSlideInRight();
		});
		list->addElement(btnRight, esize);
		
		list->setPosition(Point(10, 10));
		node->addChild(list, 0);
	}
	
}
