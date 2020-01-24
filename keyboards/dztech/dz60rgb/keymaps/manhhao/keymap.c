#include QMK_KEYBOARD_H

#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))
#define IS_COMMAND_GAY() (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

enum custom_keycodes {
    K_AE = SAFE_RANGE,
    K_OE,
    K_UE,
	K_SS,
	K_QUOT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GESC,        KC_1,    KC_2,      KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,      KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CTL_T(KC_CAPS), KC_A,    KC_S,      KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, K_QUOT,      KC_ENT,
             KC_LSFT,   KC_Z,    KC_X,    	KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MO(2), 			 KC_UP,   KC_SLSH,
        KC_LCTL,        KC_LGUI, KC_LALT,		                   KC_SPC,                        KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_PGDOWN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       KC_PSCR,
            _______,      _______, _______, RGB_TOG, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,  KC_DEL,  _______,
        _______, _______, _______,                            _______,                   _______, _______, KC_HOME,  KC_END,  KC_INS
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, K_UE,    _______, K_OE,    _______, _______, _______, _______,
        _______, K_AE,    K_SS,    _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch(keycode) {
        case K_AE:
		    if (record->event.pressed && IS_COMMAND_GAY()) {
				SEND_STRING(SS_LSFT("'a"));
			}
			else if(record->event.pressed && !IS_COMMAND_GAY()) { 
				SEND_STRING(SS_LSFT("'")"a");
			}
            return false;
        case K_OE:
		    if (record->event.pressed && IS_COMMAND_GAY()) {
				SEND_STRING(SS_LSFT("'o"));
			}
			else if(record->event.pressed && !IS_COMMAND_GAY()) { 
				SEND_STRING(SS_LSFT("'")"o");
			}
            return false;
        case K_UE:
		    if (record->event.pressed && IS_COMMAND_GAY()) {
				SEND_STRING(SS_LSFT("'u"));
			}
			else if(record->event.pressed && !IS_COMMAND_GAY()) { 
				SEND_STRING(SS_LSFT("'")"u");
			}
            return false;
		case K_SS:
			if (record->event.pressed)
				SEND_STRING(SS_RALT("s"));
            return false;
		case K_QUOT:
		    if (record->event.pressed && IS_COMMAND()) {
				SEND_STRING((SS_LSFT("' ")));
			}
			else if(record->event.pressed && !IS_COMMAND()) { 
				SEND_STRING("' ");
			}
            return false;
       }
    return true;
};

void matrix_init_user() {
	rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}