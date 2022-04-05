
export BUILD_ROOT = $(shell pwd)

export INCLUDE_PATH = $(BUILD_ROOT)/_include \
					  $(BUILD_ROOT)/pool \
					  $(BUILD_ROOT)/misc 

BUILD_DIR = $(BUILD_ROOT)/misc/ \
			$(BUILD_ROOT)/pool/ \
			$(BUILD_ROOT)/app/ 

export DEBUG = true

