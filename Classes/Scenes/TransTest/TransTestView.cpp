//
//  TransTestView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/30.
//
//

#include "TransTestView.h"
#include "../../Utils/WidgetUtils.h"
#include "../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	TransTestView::TransTestView() {
	}

	TransTestView::~TransTestView() {
	}

	void TransTestView::init(Scene* scene) {
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
		const Size vsize(440, 260);
		const Size tsize(220, 42);
		SimpleTileView* tileView = SimpleTileView::create(TileViewType::Vertical, tsize, vsize);
		
#define ADD_BUTTON(sceneChanger, name)							do { Button* btnTrans = WidgetUtils::createTTFButton(name, [=]() { emitSelectTrans(sceneChanger); }); tileView->addElement(btnTrans); } while(false)
		ADD_BUTTON(SceneChangers::RotoZoom(0.5f, true), "RotoZoom");
		ADD_BUTTON(SceneChangers::JumpZoom(0.5f, true), "JumpZoom");
		ADD_BUTTON(SceneChangers::MoveInL(0.5f, true), "MoveInL");
		ADD_BUTTON(SceneChangers::MoveInR(0.5f, true), "MoveInR");
		ADD_BUTTON(SceneChangers::MoveInT(0.5f, true), "MoveInT");
		ADD_BUTTON(SceneChangers::MoveInB(0.5f, true), "MoveInB");
		ADD_BUTTON(SceneChangers::SlideInL(0.5f, true), "SlideInL");
		ADD_BUTTON(SceneChangers::SlideInR(0.5f, true), "SlideInR");
		ADD_BUTTON(SceneChangers::SlideInT(0.5f, true), "SlideInT");
		ADD_BUTTON(SceneChangers::ShrinkGrow(0.5f, true), "ShrinkGrow");
		ADD_BUTTON(SceneChangers::FlipL(0.5f, true), "FlipL");
		ADD_BUTTON(SceneChangers::FlipR(0.5f, true), "FlipR");
		ADD_BUTTON(SceneChangers::FlipU(0.5f, true), "FlipU");
		ADD_BUTTON(SceneChangers::FlipD(0.5f, true), "FlipD");
		ADD_BUTTON(SceneChangers::FlipAngularL(0.5f, true), "FlipAngularL");
		ADD_BUTTON(SceneChangers::FlipAngularR(0.5f, true), "FlipAngularR");
		ADD_BUTTON(SceneChangers::ZoomFlipL(0.5f, true), "ZoomFlipL");
		ADD_BUTTON(SceneChangers::ZoomFlipR(0.5f, true), "ZoomFlipR");
		ADD_BUTTON(SceneChangers::ZoomFlipU(0.5f, true), "ZoomFlipU");
		ADD_BUTTON(SceneChangers::ZoomFlipD(0.5f, true), "ZoomFlipD");
		ADD_BUTTON(SceneChangers::ZoomFlipAngularL(0.5f, true), "ZoomFlipAngularL");
		ADD_BUTTON(SceneChangers::ZoomFlipAngularR(0.5f, true), "ZoomFlipAngularR");
		ADD_BUTTON(SceneChangers::Fade(0.5f, Color3B::GRAY, true), "Fade");
		ADD_BUTTON(SceneChangers::CrossFade(0.5f, true), "CrossFade");
		ADD_BUTTON(SceneChangers::TurnOffTiles(0.5f, true), "TurnOffTiles");
		ADD_BUTTON(SceneChangers::SplitCols(0.5f, true), "SplitCols");
		ADD_BUTTON(SceneChangers::SplitRows(0.5f, true), "SplitRows");
		ADD_BUTTON(SceneChangers::FadeTR(0.5f, true), "FadeTR");
		ADD_BUTTON(SceneChangers::FadeBL(0.5f, true), "FadeBL");
		ADD_BUTTON(SceneChangers::FadeUp(0.5f, true), "FadeUp");
		ADD_BUTTON(SceneChangers::FadeDown(0.5f, true), "FadeDown");
#undef ADD_BUTTON
		
		tileView->setPosition(Point(20, 10));
		node->addChild(tileView, 0);
	}

}
