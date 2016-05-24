LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := java2struct.c
LOCAL_MODULE := java2struct
LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)
