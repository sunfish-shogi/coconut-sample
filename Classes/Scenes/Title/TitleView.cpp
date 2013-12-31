//
//  TitleView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "TitleView.h"
#include "../../Utils/WidgetUtils.h"
#include "../../Utils/ImageUtils.h"
#include <coconut/widgets/list_view/SimpleListView.h>
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	TitleView::TitleView() {
	}

	TitleView::~TitleView() {
	}

	void TitleView::init(Scene* scene) {
		_scene = scene;
		
		Node* node = Node::create();
		node->setPosition(LayoutUtils::visibleCenter() - Point(240, 160));
		_scene->addChild(node);
		
		// background
		Sprite* bg = Sprite::create("bg.png");
		bg->setScale(2.0f * ImageUtils::scale4OneSizeImage());
		bg->setPosition(Point(240, 160));
		node->addChild(bg, INT_MIN);
		
		// close
		Button* btnClose = Button::createWithSpriteFileName("CloseNormal.png", "CloseSelected.png", [this]() {
			emitSelectClose();
		});
		btnClose->setScale(ImageUtils::scale4OneSizeImage() * 2.0f);
		btnClose->setPosition(Point(455, 25));
		node->addChild(btnClose, INT_MAX);
		
		// list view
		const Size vsize(460, 300);
		const Size esize(460, 42);
		SimpleListView* list = SimpleListView::create(ListDirection::VERTICAL, vsize);
		
		Button* btnPuzzle = WidgetUtils::createTTFButton("15 Puzzle", [this]() {
			emitSelectSlidePuzzle();
		});
		list->addElement(btnPuzzle, esize);
		
		Button* btnTrans = WidgetUtils::createTTFButton("Trans Test", [this]() {
			emitSelectSceneTransTest();
		});
		list->addElement(btnTrans, esize);
		
		Button* btnOverlay = WidgetUtils::createTTFButton("Overlay Test", [this]() {
			emitSelectOverlayTest();
		});
		list->addElement(btnOverlay, esize);
		
		Button* btnGesture = WidgetUtils::createTTFButton("Gesture Test", [this]() {
			emitSelectGestureTest();
		});
		list->addElement(btnGesture, esize);
		
		Button* btnSchedule = WidgetUtils::createTTFButton("Schedule Test", [this]() {
			emitSelectScheduleTest();
		});
		list->addElement(btnSchedule, esize);
		
		Button* btnNetwork = WidgetUtils::createTTFButton("Network Test", [this]() {
			emitSelectNetworkTest();
		});
		list->addElement(btnNetwork, esize);
		
		list->setPosition(Point(10, 10));
		node->addChild(list, 0);
	}
	
}
