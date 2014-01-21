LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

include ../Libraries/coconut/Android.mk

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

CLASSES_SRC_FILES := $(shell find $(LOCAL_PATH)/../../Classes -name "*.cpp")
LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(CLASSES_SRC_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(COCONUT_SRC_FILES:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
                    $(LOCAL_PATH)/../../cocos2d/cocos \
                    $(LOCAL_PATH)/../../cocos2d/cocos/editor-support \
                    $(LOCAL_PATH)/../../cocos2d/extensions \
                    $(COCONUT_C_INCLUDES)

#LOCAL_LDLIBS     := -llog 

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
#LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
#LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dxandroid_static

include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_STATIC_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
#$(call import-module,Box2D)
$(call import-module,extensions)
$(call import-module,network)
$(call import-module,editor-support/cocosbuilder)
