CC := gcc

ifeq ($(example),)
$(error No example specified. make example=path/to/example)
endif

BUILD_FILES := $(wildcard $(example)/*.c)

all: example

example:
	$(CC) -lawry -o bin/example $(BUILD_FILES)