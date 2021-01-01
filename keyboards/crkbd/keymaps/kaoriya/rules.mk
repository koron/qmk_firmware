SRC += layer.c
# Enable console, disable OLED or RGBLIGHT
#CONSOLE_ENABLE = yes

# Enable OLED
OLED_DRIVER_ENABLE = yes
SRC += oled.c

# Mouse keys
MOUSEKEY_ENABLE = yes

# Audio control and System control: for Vol+, Vol-, and Mute
EXTRAKEY_ENABLE = yes

# Enable WS2812 RGB underlight
RGBLIGHT_ENABLE = yes

# Link-Time-Optimization: for small firmware
LTO_ENABLE = yes

## Enable RGB Matrix
#RGBLIGHT_ENABLE = no
#RGB_MATRIX_ENABLE = yes
