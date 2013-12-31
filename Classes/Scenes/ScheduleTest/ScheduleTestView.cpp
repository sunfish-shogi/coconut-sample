//
//  ScheduleTestView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/01.
//
//

#include "ScheduleTestView.h"
#include "../../Utils/WidgetUtils.h"
#include "../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

namespace coconut_sample {

	ScheduleTestView::ScheduleTestView() {
	}

	ScheduleTestView::~ScheduleTestView() {
	}

	void ScheduleTestView::init(Scene* scene) {
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
		
		// image
		Point imgPos(240, 200);
		float imgScale = 2.0f * ImageUtils::scale4OneSizeImage();
		Sprite* image = Sprite::create("Icon.png");
		image->setScale(imgScale);
		image->setPosition(imgPos);
		node->addChild(image);
		
		// schedule
		_scheduleRotate = nullptr;
		_scheduleScale = nullptr;
		_scaleCount = 0.0f;
		
		Button* btnRotate = WidgetUtils::createTTFButton("Rotate", [=]() {
			if (!_scheduleRotate) {
				_scheduleRotate = _scheduleManager->scheduleForever(0.5f, 0.0f, [=]() {
					image->setRotation(image->getRotation() + 30.0f);
				});
			} else {
				_scheduleManager->cancel(_scheduleRotate);
				_scheduleRotate = nullptr;
			}
		});
		btnRotate->setPosition(Point(240, 90));
		node->addChild(btnRotate, INT_MAX);
		
		Button* btnScale = WidgetUtils::createTTFButton("Scale", [=]() {
			if (!_scheduleScale) {
				_scheduleScale = _scheduleManager->scheduleForever(0.5f, 0.0f, [=]() {
					_scaleCount += 1.0f;
					image->setScale(imgScale * (sinf(_scaleCount * M_PI / 6.0f) * 0.5f + 1.0f));
				});
			} else {
				_scheduleManager->cancel(_scheduleScale);
				_scheduleScale = nullptr;
			}
		});
		btnScale->setPosition(Point(240, 40));
		node->addChild(btnScale, INT_MAX);
	}
	
}
