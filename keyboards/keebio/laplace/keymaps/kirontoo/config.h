#ifndef CONFIG_H
#define CONFIG_H

#include "config.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCB10
#define PRODUCT_ID      0x1147
#define DEVICE_VER      0x0100
#define MANUFACTURER    Keebio
#define PRODUCT         Laplace
#define DESCRIPTION     40 percent staggered keyboard

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS {D3, F4, D2, F5, D7, B4, C6, E6}
#define MATRIX_COL_PINS {D1, F6, F7, B1, B3, B2, B6}


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200
#define RETRO_TAPPING
#define PERMISSIVE_HOLD

/* Configure mousekey behavior */
#define MOUSEKEY_DELAY             100
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         10
#define MOUSEKEY_TIME_TO_MAX       20
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif
