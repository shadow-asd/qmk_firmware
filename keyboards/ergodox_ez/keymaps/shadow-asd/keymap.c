#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_spanish.h"

enum layers {
    BASE, // default layer
    REALMOD, // REALMOD
    MDIA,  // media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
  KC_QUOTHASHAMPER,
  KC_QDOLLAR,
  KC_YCLR,
  KC_OCOLN,
  KC_UCLR,
  KC_ALTAT,
  KC_HLBRC,
  KC_ILPRN,
  KC_EMINS,
  KC_ACOMM,
  KC_DOTCIRCRABK,
  KC_BRPCDEL,
  KC_UNPERC6,
  KC_EXLMPIPE4,
  KC_QUESBSLS2,
  KC_K0,
  KC_X8,
  KC_METACLK,
  KC_ENTERSPC,
  KC_BGRV,
  KC_DSLSH,
  KC_LSCLN,
  KC_CPLUS,
  KC_JTULD,
  KC_ZACU,
  KC_GLABK,
  KC_TEQL,
  KC_NDQUOT,
  KC_SRPRN,
  KC_RRBRC,
  KC_ESCASTR,
  KC_JTILD,
  KC_ZACUT,
  KC_NDQUO,
  KCU_P7,
  KC_W1,
  KC_M3,
  KCU_F5,
  KC_V9,
  KC_BSPCDEL,
  VSRN,
  G_START,
  G_EXIT,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
        * ,--------------------------------------------------.           ,--------------------------------------------------.
        * |        | Q    | Y    | O    |U     | #    |      |           |      |B     |D     |L     |C     |J     |Z       |
        * | tab    | q  $ | y  { | o  : |u   } | '  & |      |           |      |b   ` |d   / |l   ; |c    +|j   ~ |z    ´  |
        * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
        * |        |H     |I     |E     |A     |^     |      |           |      |G     |T     |N     |S     |R     |        |
        * |alt   @ |h   [ |i   ( |e   - |a   , |.    >|      |           |      |g   < |t   = |n   " |s   ) |r    ]|Esc  *  |
        * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        * |        |%     | |    |\     |K     |X     |------|           |------|P     |W     |M     |F     |V     |Ñ       |
        * |bspc del|_   6 | !   4|?   2 |k    0|x    8|      |           |      |p   7 |w    1|m   3 |f   5 |v   9 |ñ       |
        * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        * |        |      |      |      | l-clk|      |      |           |      |      |      |      |      |      |        |
        * |caps    |      |      |      | Meta | ctrl |spcRet|           | altGr|shift |      |      |      |      |        |
        * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
        *   |met(6)|met(4)|met(2)|met(0)|met(8)|                                       |met(7)|met(1)|met(3)|met(5)|met(9) |
        *   `----------------------------------'                                       `----------------------------------´
        *                                        ,-------------.       ,-------------.
        *                                        |      |layer2|       |      |layer1|
        *                                 ,------|------|------|       |------+--------+------.
        *                                 |      |      |      |       |      |        |      |
        *                                 |      |      |------|       |------|        |      |
        *                                 |      |      |reset |       |      |        |      |
        *                                 `--------------------'       `----------------------'
        */
    [BASE] = LAYOUT_ergodox_pretty(
        // left hand
        KC_TAB,        KC_QDOLLAR,   KC_YCLR,      KC_OCOLN,     KC_UCLR,     KC_QUOTHASHAMPER,KC_NO,          KC_NO,  KC_BGRV, KC_DSLSH,     KC_LSCLN, KC_CPLUS,   KC_JTILD, KC_ZACU,
        KC_ALTAT,      KC_HLBRC,     KC_ILPRN,     KC_EMINS,     KC_ACOMM,    KC_DOTCIRCRABK,  KC_NO,          KC_NO,  KC_GLABK,KC_TEQL,      KC_NDQUO, KC_SRPRN,   KC_RRBRC, KC_ESCASTR,
        KC_BSPCDEL,    KC_UNPERC6,   KC_EXLMPIPE4, KC_QUESBSLS2, KC_K0,       KC_X8,                                   KCU_P7,  KC_W1,        KC_M3,    KCU_F5,     KC_V9,    ES_NTIL,
        KC_CAPSLOCK,   KC_NO,        KC_NO,        KC_NO,        KC_METACLK,  KC_RCTRL,     KC_ENTERSPC,       KC_ALGR,KC_LSFT, KC_NO,        KC_NO,    KC_NO,      KC_NO,    KC_NO,
        LGUI(ES_6),    LGUI(ES_4),   LGUI(ES_2),   LGUI(ES_0),   LGUI(ES_8),                                             LGUI(ES_7),LGUI(ES_1), LGUI(ES_3),LGUI(ES_5),LGUI(ES_9),
                                                                              KC_NO,  TO(MDIA),               KC_NO, TO(REALMOD),
                                                                                      KC_NO,                  KC_NO,
                                                                              KC_NO,  KC_NO,  RESET,          KC_NO, KC_NO, KC_NO

    ),
    /* Keymap 1: REALMODol Layer
        *
        * ,---------------------------------------------------.           ,--------------------------------------------------.
        * |Version  |  F1  | copy |  F3  |  F4  |  F5  |      |           |      |  pUp | cut  | right|  F9  |  down|   F11  |
        * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
        * |         | left | F2   |      |      |      |      |           |      | F6   |  F7  |      |  F8  | F10  |   F12  |
        * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        * |         |      |      |      |  up  |      |------|           |------|paste |      |      | pDowm|      |        |
        * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        * |         |      |      |      |      |      |      |           |altGr |      |      |      |      |      |        |
        * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
        *   |   6   |   4  |  2   |  0   |  8   |                                       |   7  |  1   |  3   |  5   |  9   |
        *   `-----------------------------------'                                       `----------------------------------'
        *                                        ,-------------.       ,-------------.
        *                                        |      | wup  |       |mup   |layer0|
        *                                 ,------|------|------|       |------+------+------.
        *                                 |      |      |wdown |       |rclick|mright|      |
        *                                 |      |mleft |------|       |------|      |      |
        *                                 |      |      |      |       | mdown|      |      |
        *                                 `--------------------'       `--------------------'
        */
    [REALMOD] = LAYOUT_ergodox_pretty(
        VSRN,    KC_F1,   C(ES_C), KC_F3,   KC_F4,  KC_F5,   _______,     _______, KC_PGUP,   C(ES_X), KC_RGHT, KC_F9,   KC_DOWN, KC_F11,
        _______, KC_LEFT, KC_F2,   _______, _______,_______, _______,     _______, KC_F6,     KC_F7,   _______, KC_F8,   KC_F10,  KC_F12,
        _______, _______, _______, _______, KC_UP,  _______,                       C(ES_V),   _______, _______, KC_PGDN, _______, _______,
        _______, _______, _______, _______, _______,_______, _______,     _______, _______,   _______, _______, _______, _______, _______,
        ES_6,    ES_4,    ES_2,    ES_0,    ES_8,                                             ES_7,    ES_1,    ES_3,    ES_5,    ES_9,
                                                    _______, KC_MS_WH_UP,     KC_MS_U, TO(BASE),
                                                             KC_MS_WH_DOWN,     KC_BTN1,
                                            _______,KC_MS_L, _______,     KC_MS_D, KC_MS_R, _______
    ),
    /* Keymap 2: Media and mouse keys
        *
        * ,--------------------------------------------------.           ,--------------------------------------------------.
        * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
        * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
        * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | volup  |
        * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |  Play  |
        * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      | voldwn |
        * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
        *   |      |      |      |      |      |                                       |      |      |      |      |  Mute |
        *   `----------------------------------'                                       `----------------------------------'
        *                                        ,-------------.       ,-------------.
        *                                        |      |Layer1|       |      |      |
        *                                 ,------|------|------|       |------+------+------.
        *                                 |      |      |      |       |      |      |Brwser|
        *                                 |      |      |------|       |------|      |Back  |
        *                                 |      |      |      |       |      |      |      |
        *                                 `--------------------'       `--------------------'
        */
    [MDIA] = LAYOUT_ergodox_pretty(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_MPRV, KC_MNXT, _______, KC_VOLD,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, KC_MUTE,

                                                    _______, TO(BASE),     _______, _______,
                                                             _______,     _______,
                                            _______, _______,_______,     _______, _______, KC_WBAK
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QUOTHASHAMPER:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
                clear_mods();
                register_code16(ES_HASH);
                } else if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_AMPR);
                } else {
                register_code(ES_QUOT);
                }
            // to send the signal for release of key
            } else {
                unregister_code16(ES_HASH);
                unregister_code(ES_QUOT);
                unregister_code16(ES_AMPR);
            }
            return false;
        case KC_QDOLLAR:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_DLR);
                } else {
                register_code(KC_Q);
                }
            } else {
                unregister_code(ES_Q);
                unregister_code16(ES_DLR);
            }
            return false;
        case KC_YCLR:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_LCBR);
                } else {
                register_code(ES_Y);
                }
            } else {
                unregister_code(ES_Y);
                unregister_code16(ES_LCBR);
            }
            return false;
        case KC_OCOLN:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_COLN);
                } else {
                register_code(ES_O);
                }
            } else {
                unregister_code(ES_O);
                unregister_code16(ES_COLN);
            }
            return false;
        case KC_UCLR:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_LCBR);
                } else {
                register_code(ES_U);
                }
            } else {
                unregister_code(ES_U);
                unregister_code16(ES_LCBR);
            }
            return false;
        case KC_HLBRC:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_LBRC);
                register_code16(KC_ALGR);
                } else {
                register_code(ES_H);
                }
            } else {
                unregister_code(ES_H);
                unregister_code16(ES_LBRC);
            }
            return false;
        case KC_ILPRN:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_LPRN);
		register_code16(KC_ALGR);
                } else {
                register_code(ES_I);
                }
            } else {
                unregister_code(ES_I);
                unregister_code16(ES_LPRN);
            }
            return false;
        case KC_EMINS:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_MINS);
                register_code16(KC_ALGR);
                } else {
                register_code(ES_E);
                }
            } else {
                unregister_code(ES_E);
                unregister_code16(ES_MINS);
            }
            return false;
        case KC_ACOMM:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_COMM);
                } else {
                register_code(ES_A);
                }
            } else {
                unregister_code(ES_A);
                unregister_code16(ES_COMM);
            }
            return false;
        case KC_DOTCIRCRABK:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
                clear_mods();
                register_code16(ES_CIRC);
                } else if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_RABK);
                } else {
                register_code(ES_DOT);
                }
            } else {
                unregister_code16(ES_CIRC);
                unregister_code(ES_DOT);
                unregister_code16(ES_RABK);
            }
            return false;
        case KC_ALTAT:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_AT);
                } else {
                register_code16(KC_LALT);
                }
            } else {
                unregister_code16(ES_AT);
                unregister_code16(KC_LALT);
            }
            return false;
        case KC_BSPCDEL:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(KC_DEL);
                register_code(KC_ALGR);
                } else {
                register_code16(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code16(KC_BSPC);
            }
            return false;
        case KC_UNPERC6:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
                clear_mods();
                register_code16(ES_PERC);
                } else if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_6);
                register_code(KC_ALGR);
                } else {
                register_code16(ES_UNDS);
                }
            } else {
                unregister_code16(ES_PERC);
                unregister_code16(ES_UNDS);
                unregister_code16(ES_6);
            }
            return false;
        case KC_EXLMPIPE4:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
                clear_mods();
                register_code16(ES_PIPE);
                register_code16(KC_LSHIFT);
                } else if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_4);
                register_code(KC_ALGR);
                } else {
                register_code16(ES_EXLM);
                }
            } else {
                unregister_code16(ES_PIPE);
                unregister_code16(ES_EXLM);
                unregister_code16(ES_4);
            }
            return false;
        case KC_QUESBSLS2:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
                clear_mods();
                register_code16(ES_BSLS);
                } else if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_2);
                register_code(KC_ALGR);
                } else {
                register_code16(ES_QUES);
                }
            } else {
                unregister_code16(ES_BSLS);
                unregister_code16(ES_QUES);
                unregister_code16(ES_2);
            }
            return false;
        case KC_K0:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_0);
                register_code(KC_ALGR);
                } else {
                register_code(ES_K);
                }
            } else {
                unregister_code(ES_K);
                unregister_code16(ES_0);
            }
            return false;
        case KC_X8:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code(ES_8);
                register_code(KC_ALGR);
                } else {
                register_code(ES_X);
                }
            } else {
                unregister_code(ES_X);
                unregister_code16(ES_8);
            }
            return false;
        case KC_METACLK:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(KC_BTN1);
                } else {
                register_code(KC_LGUI);
                }
            } else {
                unregister_code(KC_BTN1);
                unregister_code16(KC_LGUI);
            }
            return false;
        case KC_ENTERSPC:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(KC_ENTER);
                register_code(KC_ALGR);
                } else {
                register_code16(KC_SPC);
                }
            } else {
                unregister_code16(KC_ENTER);
                unregister_code16(KC_SPC);
            }
            return false;
        case KC_BGRV:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_GRV);
                } else {
                register_code(ES_B);
                }
            } else {
                unregister_code16(ES_GRV);
                unregister_code(ES_B);
            }
            return false;
        case KC_DSLSH:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_SLSH);
                register_code16(KC_ALGR);
                } else {
                register_code(ES_D);
                }
            } else {
                unregister_code16(ES_SLSH);
                unregister_code(ES_D);
            }
            return false;
        case KC_LSCLN:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_SCLN);
                } else {
                register_code(ES_L);
                }
            } else {
                unregister_code16(ES_SCLN);
                unregister_code(ES_L);
            }
            return false;
        case KC_CPLUS:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_PLUS);
                register_code16(KC_ALGR);
                } else {
                register_code(ES_C);
                }
            } else {
                unregister_code16(ES_PLUS);
                unregister_code(ES_C);
            }
            return false;
        case KC_JTILD:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_TILD);
                } else {
                register_code(ES_J);
                }
            } else {
                unregister_code16(ES_TILD);
                unregister_code(ES_J);
            }
            return false;
        case KC_ZACU:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_ACUT);
                } else {
                register_code(ES_Z);
                }
            } else {
                unregister_code16(ES_ACUT);
                unregister_code(ES_Z);
            }
            return false;
        case KC_GLABK:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_LABK);
                } else {
                register_code(ES_G);
                }
            } else {
                unregister_code16(ES_LABK);
                unregister_code(ES_G);
            }
            return false;
        case KC_TEQL:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_EQL);
		register_code16(KC_ALGR);
                } else {
                register_code(ES_T);
                }
            } else {
                unregister_code16(ES_EQL);
                unregister_code(ES_T);
            }
            return false;
        case KC_NDQUO:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_DQUO);
                } else {
                register_code(ES_N);
                }
            } else {
                unregister_code16(ES_DQUO);
                unregister_code(ES_N);
            }
            return false;
        case KC_SRPRN:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_RPRN);
                } else {
                register_code(ES_S);
                }
            } else {
                unregister_code16(ES_RPRN);
                unregister_code(ES_S);
            }
            return false;
        case KC_RRBRC:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_RBRC);
                register_code16(KC_ALGR);
                } else {
                register_code(ES_R);
                }
            } else {
                unregister_code16(ES_RBRC);
                unregister_code(ES_R);
            }
            return false;
        case KC_ESCASTR:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_ASTR);
                register_code16(KC_ALGR);
                } else {
                register_code16(KC_ESC);
                }
            } else {
                unregister_code16(ES_ASTR);
                unregister_code16(KC_ESC);
            }
            return false;
        case KCU_P7:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_7);
                register_code(KC_ALGR);
                } else {
                register_code16(ES_P);
                }
            } else {
                unregister_code16(ES_7);
                unregister_code16(ES_P);
            }
            return false;
        case KC_W1:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code16(ES_1);
                register_code(KC_ALGR);
                } else {
                register_code16(ES_W);
                }
            } else {
                unregister_code16(ES_1);
                unregister_code16(ES_W);
            }
            return false;
        case KC_M3:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code(ES_3);
                register_code(KC_ALGR);
                } else {
                register_code16(ES_M);
                }
            } else {
                unregister_code16(ES_3);
                unregister_code16(ES_M);
            }
            return false;
        case KCU_F5:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code(ES_5);
                register_code(KC_ALGR);
                } else {
                register_code(ES_F);
                }
            } else {
                unregister_code(ES_5);
                unregister_code(ES_F);
            }
            return false;
        case KC_V9:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_ALGR)){
                clear_mods();
                register_code(ES_9);
                register_code(KC_ALGR);
                } else {
                register_code(ES_V);
                }
            } else {
                unregister_code(ES_9);
                unregister_code(ES_V);
            }
            return false;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
