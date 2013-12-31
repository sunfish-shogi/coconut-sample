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
		
		// list view
		const Size vsize(460, 300);
		const Size esize(460, 42);
		SimpleListView* list = SimpleListView::create(ListDirection::VERTICAL, vsize);
		
		// normal
		Button* btnNormal = WidgetUtils::createTTFButton("Normal", [this]() {
			emitSelectNormal();
		});
		list->addElement(btnNormal, esize);
		
		// slide in (top)
		Button* btnTop = WidgetUtils::createTTFButton("Slide In Top", [this]() {
			emitSelectSlideInTop();
		});
		list->addElement(btnTop, esize);
		
		// slide in (bottom)
		Button* btnBottom = WidgetUtils::createTTFButton("Slide In Bottom", [this]() {
			emitSelectSlideInBottom();
		});
		list->addElement(btnBottom, esize);
		
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
