//
//  NetworkTestView.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2014/01/07.
//
//

#include "NetworkTestView.h"
#include "../../Utils/WidgetUtils.h"
#include "../../Utils/ImageUtils.h"
#include <coconut/utils/LayoutUtils.h>

USING_NS_CC;
using namespace coconut;

#define Z_ORDER_ROOT									1
#define Z_ORDER_BTN_GET								101
#define Z_ORDER_RESULT								102

#define TAG_ROOT											1
#define TAG_RESULT										102

namespace coconut_sample {

	NetworkTestView::NetworkTestView() {
	}

	NetworkTestView::~NetworkTestView() {
	}

	void NetworkTestView::init(Scene* scene) {
		_scene = scene;
		
		Node* node = Node::create();
		node->setPosition(LayoutUtils::visibleCenter() - Point(240, 160));
		_scene->addChild(node, Z_ORDER_ROOT, TAG_ROOT);
		
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
		
		// get button
		Button* btnGet = WidgetUtils::createTTFButton("Get", [this]() {
			get();
		});
		btnGet->setPosition(Point(240, 295));
		node->addChild(btnGet, Z_ORDER_BTN_GET);
		
		// result label
		LabelTTF* lblResult = LabelTTF::create("", "Helvetica", 16, Size(460, 250), TextHAlignment::LEFT, TextVAlignment::TOP);
		lblResult->setPosition(Point(240, 135));
		node->addChild(lblResult, Z_ORDER_RESULT, TAG_RESULT);
	}
	
	void NetworkTestView::get() {
		const char* url = "https://raw.github.com/sunfish-shogi/coconut-sample/master/README.md";
		LabelTTF* lblResult = (LabelTTF*)_scene->getChildByTag(TAG_ROOT)->getChildByTag(TAG_RESULT);
		lblResult->setString("");
		_http.get(url, [=](const HttpManager::Response& response) {
			if (response.code == 200) {
				std::string body(response.body.buffer(), response.body.size());
				lblResult->setString(body);
				std::cout << body << std::endl;
			} else {
				log("ERROR: HTTP Code=%d", response.code);
				log("ERROR: %s", response.error);
			}
		});
	}
	
}
