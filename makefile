
include config.mk

all:
	@for dir in $(BUILD_DIR); \
	do \
		make -C $$dir; \
	done

clear:
	rm -rf app/link_obj app/dep ./engine

memorycheck:
	