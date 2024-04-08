/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include <stdio.h>

#include "keymap_bepo.h"

char wpm_str[30];

enum layers {
    _BEPO = 0,
    _CODE,
    _RAISE,
    _LOWER
};

#define BP_EA BP_EACU
#define BP_AG BP_AGRV
#define BP_EG BP_EGRV
#define BP_CO BP_COMM
#define BP_DT BP_DOT
#define LS KC_LSFT
#define BP_DOL BP_DLR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BEPO
 *
 *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
 *  |   Tab  |    B   |   É   |    P   |    O   |    È   |                                            |    ^   |   V    |   D    |   L    |   J    |   Ç    |
 *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
 *  |  Bksp  |    A   |   U   |    I   |    E   |    ,   |                                            |    C   |   T    |   S    |   R    |   N    |   M    |
 *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
 *  | LShift |    À   |   Y   |    X   |    .   |    K   | Escape  |LMSH_LWR|      |AltLower|  Raise  |    '   |   Q    |   G    |   H    |   F    | RShift |
 *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
 *                            | Super  | LCtrl  |  LAlt  |  Space  | Lower  |      |  Ralt  |  Enter  | Escape |   Z    |   W    |
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            `---------------------------------------------'      `---------------------------------------------'
 */
    [_BEPO] = LAYOUT(
      KC_ESC , BP_B   , BP_EA , BP_P   , BP_O   , BP_EG  ,                    /* */                    BP_DCIR  , BP_V   , BP_D   , BP_L   , BP_J   , BP_Z ,
      KC_TAB , BP_A   , BP_U  , BP_I   , BP_E   , BP_CO  ,                    /* */                    BP_C   , BP_T   , BP_S   , BP_R   , BP_N   , BP_M ,
      KC_LSFT, BP_AG  , BP_Y  , BP_X   , BP_DT  , BP_K   , KC_PSCR,  KC_MUTE, /* */  KC_VOLD , KC_VOLU,BP_QUOT  , BP_Q   , BP_G   , BP_H   , BP_F   , BP_W ,
                      KC_LCTL, KC_LGUI, KC_LALT, LT(_LOWER, KC_BSPC) , LT(_RAISE, KC_DEL) ,/* */ LT(_CODE, KC_ENT), KC_SPACE , KC_ALGR , BP_UNDS   , BP_CCED
    ),


/*
 * Lower Layer:
 *
 *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
 *  |   $    |   "    |   «   |   »    |   (    |   )    |                                            |   @    |    +   |   -    |   /    |   *    |   =    |
 *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
 *  |        |        |       |        |        |        |                                            |CapsLock|  Left  |  Down  |   Up   | Right  |   %    |
 *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
 *  |        |        |       |        |        |        |    %    |PrintScr|      |        |         |        |        |        |        |        |        |
 *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            `---------------------------------------------'      `---------------------------------------------'
 */
    [_CODE] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT,                   /* */                   BP_HASH, BP_EQL, BP_DQUO,  BP_AT, BP_PERC, BP_TILD ,
      KC_TRNS, BP_LABK, BP_LBRC, BP_LPRN, BP_LCBR, BP_DOL,                   /* */                   BP_PIPE, BP_RCBR, BP_RPRN, BP_RBRC  ,BP_RABK, BP_UNDS,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, BP_AMPR, KC_NO, KC_NO, KC_NO, KC_NO, BP_BSLS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO
    ),

/*
 * Raise Layer:
 *
 *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
 *  |        |        |   7   |    8   |   9    |        |                                            |        |   F7   |   F8   |   F9   |  F10   |  F13   |
 *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
 *  |        |        |   4   |    5   |   6    |        |                                            |        |   F4   |   F5   |   F6   |  F11   |  F14   |
 *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
 *  |        |        |   1   |    2   |   3    |   0    |         |        |      |        |         |        |   F1   |   F2   |   F3   |  F12   |  F15   |
 *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            `---------------------------------------------'      `---------------------------------------------'
 *
 */
    [_RAISE] = LAYOUT(
      RGB_M_R, RGB_M_K, KC_F9  , KC_F10 , KC_F11 , KC_F12 ,                 /* */                   _______, BP_7  , BP_8  , BP_9  , BP_SLSH ,  KC_NO ,
      RGB_M_SW,RGB_M_G, KC_F5  , KC_F6  , KC_F7  , KC_F8,                   /* */                   _______, BP_4  , BP_5  , BP_6  , BP_ASTR ,  KC_NO ,
      RGB_M_SN,RGB_M_B, KC_F1  , KC_F2  , KC_F3  , KC_F4, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, _______, BP_1  , BP_2  , BP_3  , BP_PLUS ,  KC_NO ,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, BP_0, KC_TRNS  , BP_MINS
    ),

    /*
 * Raise Layer:
 *
 *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
 *  |        |        |   7   |    8   |   9    |        |                                            |        |   F7   |   F8   |   F9   |  F10   |  F13   |
 *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
 *  |        |        |   4   |    5   |   6    |        |                                            |        |   F4   |   F5   |   F6   |  F11   |  F14   |
 *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
 *  |        |        |   1   |    2   |   3    |   0    |         |        |      |        |         |        |   F1   |   F2   |   F3   |  F12   |  F15   |
 *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            |        |        |        |         |        |      |        |         |        |        |        |
 *                            `---------------------------------------------'      `---------------------------------------------'
 *
 */
    [_LOWER] = LAYOUT(
      RGB_M_R, RGB_M_K, KC_NO  , KC_NO  , KC_NO  , KC_NO,                   /* */                   KC_NO, KC_HOME, KC_UP,   KC_END,  KC_NO ,  KC_NO ,
      RGB_M_SW,RGB_M_G, KC_NO  , KC_NO  , KC_NO  , KC_NO,                   /* */                   KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO ,  KC_NO ,
      RGB_M_SN,RGB_M_B, KC_NO  , KC_NO  , KC_NO  , KC_NO, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_NO ,  KC_NO ,
                               KC_P0  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  , KC_NO
    ),

// /*
//  * Template Layer:
//  *
//  *  ,----------------------------------------------------.                                            ,-----------------------------------------------------.
//  *  |        |        |       |        |        |        |                                            |        |        |        |        |        |        |
//  *  |--------+--------+-------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
//  *  |        |        |       |        |        |        |                                            |        |        |        |        |        |        |
//  *  |--------+--------+-------+--------+--------+--------+------------------.      ,------------------+--------+--------+--------+--------+--------+--------|
//  *  |        |        |       |        |        |        |         |        |      |        |         |        |        |        |        |        |        |
//  *  `-------------------------+--------+--------+--------+---------+--------|      |--------+---------+--------+--------+--------+--------------------------'
//  *                            |        |        |        |         |        |      |        |         |        |        |        |
//  *                            |        |        |        |         |        |      |        |         |        |        |        |
//  *                            `---------------------------------------------'      `---------------------------------------------'
//  *
//  */
//    [_TEMPLATE] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                   /* */                   _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                   /* */                   _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______
//     ),
//
};


#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif


#ifdef OLED_ENABLE

#include "rust.h"
#include "bongo_cat.h"

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        bongo_render_anim();
    } else {
        rust_render_anim();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	keystroke_timestamp = timer_read32();
	return true;
}

#endif /* OLED_ENABLE */
