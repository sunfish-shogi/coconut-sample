//
//  WidgetUtils.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/09/18.
//
//

#ifndef coconut_sample_WidgetUtils_h
#define coconut_sample_WidgetUtils_h

#include <coconut/widgets/button/Button.h>
#include <coconut/widgets/button/ToggleButton.h>

namespace coconut_sample {
	
	class WidgetUtils {
	private:
		
		WidgetUtils() {};
		
		static cocos2d::Node* createTTFSprite(const char* color,
																					const char* text,
																					const char* fontName,
																					int textSize);
		
		static coconut::ToggleButton* createTTFToggleButton(const char* fontName,
																												int textSize,
																												const char* color,
																												const std::function<void ()>& callback,
																												const char* text, va_list);
		
	public:
		
		static const char* defaultFontName;
		static int defaultTextSize;
		static const char* defaultColor;
		
		static cocos2d::Node* createRoundedRect(const char* color, const cocos2d::Size& size);
		
		static coconut::Button* createTTFButton(const char* text,
																						const char* fontName,
																						int textSize,
																						const char* color,
																						const std::function<void ()>& callback);
		static coconut::Button* createTTFButton(const char* text,
																						int textSize,
																						const char* color,
																						const std::function<void ()>& callback) {
			return createTTFButton(text, defaultFontName, textSize, color, callback);
		}
		static coconut::Button* createTTFButton(const char* text,
																						const char* color,
																						const std::function<void ()>& callback) {
			return createTTFButton(text, defaultFontName, defaultTextSize, color, callback);
		}
		static coconut::Button* createTTFButton(const char* text,
																						int textSize,
																						const std::function<void ()>& callback) {
			return createTTFButton(text, defaultFontName, textSize, defaultColor, callback);
		}
		static coconut::Button* createTTFButton(const char* text,
																						const std::function<void ()>& callback) {
			return createTTFButton(text, defaultFontName, defaultTextSize, defaultColor, callback);
		}
		
		static coconut::Button* createTTFButton(const char* text,
																						const char* fontName,
																						int textSize,
																						const char* color) {
			return createTTFButton(text, fontName, textSize, color, std::function<void()>());
		}
		static coconut::Button* createTTFButton(const char* text,
																						int textSize,
																						const char* color) {
			return createTTFButton(text, textSize, color, std::function<void()>());
		}
		static coconut::Button* createTTFButton(const char* text,
																						const char* color) {
			return createTTFButton(text, color, std::function<void()>());
		}
		static coconut::Button* createTTFButton(const char* text,
																						int textSize) {
			return createTTFButton(text, textSize, std::function<void()>());
		}
		static coconut::Button* createTTFButton(const char* text) {
			return createTTFButton(text, std::function<void()>());
		}
		
		static coconut::ToggleButton* createTTFToggleButton(const char* fontName,
																												int textSize,
																												const char* color,
																												const std::function<void ()>& callback,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(fontName, textSize, color, callback, text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(int textSize,
																												const char* color,
																												const std::function<void ()>& callback,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, color, callback, text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(const char* color,
																												const std::function<void ()>& callback,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn =  createTTFToggleButton(defaultFontName, defaultTextSize, color, callback, text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(int textSize,
																												const std::function<void ()>& callback,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, defaultColor, callback, text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(const std::function<void ()>& callback,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(defaultFontName, defaultTextSize, defaultColor, callback, text, params);
			va_end(params);
			return btn;
		}
		
		static coconut::ToggleButton* createTTFToggleButton(const char* fontName,
																												int textSize,
																												const char* color,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(fontName, textSize, color, std::function<void()>(), text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(int textSize,
																												const char* color,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, color, std::function<void()>(), text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(const char* color,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn =  createTTFToggleButton(defaultFontName, defaultTextSize, color, std::function<void()>(), text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(int textSize,
																												const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(defaultFontName, textSize, defaultColor, std::function<void()>(), text, params);
			va_end(params);
			return btn;
		}
		static coconut::ToggleButton* createTTFToggleButton(const char* text, ...) CC_REQUIRES_NULL_TERMINATION {
			va_list params;
			va_start(params, text);
			coconut::ToggleButton* btn = createTTFToggleButton(defaultFontName, defaultTextSize, defaultColor, std::function<void()>(), text, params);
			va_end(params);
			return btn;
		}
		
	};
	
}

#endif
