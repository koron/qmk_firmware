
# Spacific Build Options default values
OLED_DRIVER_ENABLE  = yes   # OLED_ENABLE
LED_BACK_ENABLE = yes       # LED backlight (Enable WS2812 RGB underlight.)
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)

KEYBOARD_PATHS += $(KEYBD_TOP_DIR)/local_drivers

# A workaround until #7089 is merged.
#   serial.c must not be compiled with the -lto option.
#   The current LIB_SRC has a side effect with the -fno-lto option, so use it.

CUSTOM_MATRIX = yes

LIB_SRC += local_drivers/serial.c
SRC += local_drivers/serial.c
SRC += rev2/matrix.c
SRC += rev2/split_util.c
SRC += rev2/split_scomm.c
