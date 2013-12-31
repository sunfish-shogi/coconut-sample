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
		node->setPosition(LayoutUtils::visibleCenter() - Point(160, 240));
		_scene->addChild(node);
		
		// background
		Sprite* bg = Sprite::create("bg.png");
		bg->setScale(2.0f * ImageUtils::scale4OneSizeImage());
		bg->setPosition(Point(160, 240));
		node->addChild(bg, INT_MIN);
		
		// close
		Button* btnClose = Button::createWithSpriteFileName("CloseNormal.png", "CloseSelected.png", [this]() {
			emitSelectClose();
		});
		btnClose->setScale(ImageUtils::scale4OneSizeImage() * 2.0f);
		btnClose->setPosition(Point(295, 25));
		node->addChild(btnClose, INT_MAX);
		
		// list view
		const Size vsize(300, 460);
		const Size esize(300, 42);
		SimpleListView* list = SimpleListView::create(ListDirection::VERTICAL, vsize);
		
		Button* btnTrans = WidgetUtils::createTTFButton("Scene Trans Test", [this]() {
			emitSelectSceneTransTest();
		});
		list->addElement(btnTrans, esize);
		
		Button* btnOverlay = WidgetUtils::createTTFButton("Overlay Test", [this]() {
			emitSelectOverlayTest();
		});
		list->addElement(btnOverlay, esize);
		
		list->setPosition(Point(10, 10));
		node->addChild(list, 0);
	}
	
}
