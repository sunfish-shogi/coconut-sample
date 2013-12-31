//
//  ImageUtils.h
//  coconut_sample
//
//  Created by Kubo Ryosuke on 2013/12/12.
//
//

#ifndef coconut_sample_ImageUtils_h
#define coconut_sample_ImageUtils_h

#include "cocos2d.h"
#include "../Definitions/Resolution.h"

namespace coconut_sample {
  
	class ImageUtils {
	private:
		
		ImageUtils();
		
	public:
		
		static float scale4OneSizeImage() {
			return cocos2d::Director::getInstance()->getContentScaleFactor() / CONTENT_SCALE_NORMAL;
		}
		static float length4OneSizeImage(float org) {
			return org / scale4OneSizeImage();
		}
		static cocos2d::Size size4OneSizeImage(const cocos2d::Size& org) {
			return org / scale4OneSizeImage();
		}
		
	};
	
}

#endif
