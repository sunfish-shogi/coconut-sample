//
//  WidgetUtils.cpp
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/09/18.
//
//

#include "WidgetUtils.h"
#include "ImageUtils.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace coconut;

namespace coconut_sample {
	
	const char* WidgetUtils::defaultFontName = "Helvetica";
	int WidgetUtils::defaultTextSize = 21;
	const char* WidgetUtils::defaultColor = "blue";
	
	Node* WidgetUtils::createRoundedRect(const char* color, const Size& size) {
		const char* imageName = String::createWithFormat("button_%s.png", color)->getCString();
		const Rect capInsets(ImageUtils::length4OneSizeImage(3),
												 ImageUtils::length4OneSizeImage(3),
												 ImageUtils::length4OneSizeImage(4),
												 ImageUtils::length4OneSizeImage(4));
		
		Scale9Sprite* sprite = Scale9Sprite::createWithSpriteFrameName(imageName, capInsets);
		sprite->setPreferredSize(ImageUtils::size4OneSizeImage(size));
		sprite->setScale(ImageUtils::scale4OneSizeImage());
		return sprite;
	}
		
	Node* WidgetUtils::createTTFSprite(const char* color, const char* text, const char* fontName, int textSize) {
		const float margin = 6;
		
		LabelTTF* labelTTF = LabelTTF::create(text, fontName, textSize);
		Size labelSize = labelTTF->getContentSize();
		labelSize.width += margin * 4;
		labelSize.height += margin * 2;
		labelTTF->setPosition(Point(labelSize.width/2, labelSize.height/2));
		
		Node* node = Node::create();
		node->setContentSize(labelSize);
		node->setAnchorPoint(Point(0.5f, 0.5f));
		Node* sprite = createRoundedRect(color, labelSize);
		sprite->setPosition(Point(labelSize.width/2, labelSize.height/2));
		node->addChild(sprite, 0);
		node->addChild(labelTTF, 1);
		return node;
	}
	
	Button* WidgetUtils::createTTFButton(const char* text,
																			 const char* fontName,
																			 int textSize,
																			 const char*	color,
																			 const std::function<void ()>& callback) {
		const char* lightColor = String::createWithFormat("%s_light", color)->getCString();
		Node* normalSprite = createTTFSprite(color, text, fontName, textSize);
		Node* touchingSprite = createTTFSprite(lightColor, text, fontName, textSize);
		
		Button* button = Button::createWithSprite(normalSprite, touchingSprite);
		if (callback) {
			button->onPushed(callback);
		}
		return button;
	}
	
	ToggleButton* WidgetUtils::createTTFToggleButton(const char* fontName,
																									 int textSize,
																									 const char* color,
																									 const std::function<void ()>& callback,
																									 const char* text, va_list params) {
		const char* normalImageName = String::createWithFormat("button_%s.png", color)->getCString();
		const char* touchingImageName = String::createWithFormat("button_%s_light.png", color)->getCString();
		
		ToggleButton* toggleButton = ToggleButton::create();
		toggleButton->addItemWithSprite(createTTFSprite(normalImageName, text, fontName, textSize),
																		createTTFSprite(touchingImageName, text, fontName, textSize));
		while (true) {
			const char* p = va_arg(params, char*);
			if (p == nullptr) {
				break;
			}
			toggleButton->addItemWithSprite(createTTFSprite(normalImageName, p, fontName, textSize),
																			createTTFSprite(touchingImageName, p, fontName, textSize));
		}
		if (callback) {
			toggleButton->onChanged(callback);
		}
		return toggleButton;
	}
	
}
