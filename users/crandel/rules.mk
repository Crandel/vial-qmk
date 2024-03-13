SRC += $(USER_PATH)/crandel.c
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += $(USER_PATH)/rgb.c
endif
