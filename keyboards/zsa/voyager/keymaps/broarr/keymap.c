// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    UP_DIR = SAFE_RANGE,
    FAT_ARR,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case UP_DIR:
        if (record->event.pressed) {
            SEND_STRING("../");
        } else {
            // Released
        }
        break;
    case FAT_ARR:
        if (record->event.pressed) {
            SEND_STRING("=>");
        } else {
            // Released
        }
        break;
    }
    return true;
}

void housekeeping_task_user(void) {
    if (!is_transport_connected()) {
        layer_move(5);
    } 
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /**********************************************************************************************************
     *  LAYER 0 LAYOUT                                                                                        *
     *    Colemak DH + Home Row Mods                                                                          *
     *                                                                                                        *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  ESC  │   1   │   2   │   3   │   4   │   5   │    │   6   │   7   │   8   │   9   │   0   │   -   │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  TOG  │   Q   │   W   │   F   │   P   │   B   │    │   J   │   L   │   U   │   Y   │   ;   │   \   │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  CTL  │ GUI/A │ ALT/R │ SFT/S │ CTL/T │   G   │    │   M   │ CTL/N │ SFT/E │ ALT/I │ GUI/O │   '   │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │   `   │   Z   │   X   │   C   │   D   │   V   │    │   K   │   H   │   ,   │   .   │   /   │   =   │ *
     * └───────┴───────┴───────┴───────┼───────┼───────┤    ├───────┼───────┼───────┴───────┴───────┴───────┘ *
     *                                 │       │       │    │       │       │                                 *
     *                                 │ ENTER │  TAB  │    │ BKSP  │ SPACE │                                 *
     *                                 └───────┴───────┘    └───────┴───────┘                                 *
     **********************************************************************************************************/

    [0] = LAYOUT(
        KC_ESC,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5, KC_6, KC_7,           KC_8,         KC_9,         KC_0,         KC_MINS,
        KC_TAB, KC_Q,         KC_W,         KC_F,         KC_P,         KC_B, KC_J, KC_L,           KC_U,         KC_Y,         KC_SCLN,      KC_BSLS,
        CW_TOGG, LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N),   RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,
        KC_GRV,  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V, KC_K, KC_H,           KC_COMMA,     KC_DOT,       KC_SLSH,      KC_EQL,
                                             LT(2,KC_ENT), LT(1,KC_TAB),            LT(4,KC_BSPC), LT(3,KC_SPC)
    ),

    /**********************************************************************************************************
     *  LAYER 1 LAYOUT                                                                                        *
     *    Number pad                                                                                          *
     *                                                                                                        *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │    │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │   7   │   8   │   9   │   -   │   /   │  DEL  │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │   4   │   5   │   6   │   +   │   *   │ BSPC  │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │   1   │   2   │   3   │   .   │   =   │ ENTER │ *
     * └───────┴───────┴───────┴───────┼───────┼───────┤    ├───────┼───────┼───────┴───────┴───────┴───────┘ *
     *                                 │       │       │    │       │       │                                 *
     *                                 │       │       │    │       │   0   │                                 *
     *                                 └───────┴───────┘    └───────┴───────┘                                 *
     **********************************************************************************************************/

    [1] = LAYOUT(
        KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,    KC_F8,  KC_F9, KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______,       KC_7,     KC_8,   KC_9,  KC_MINS, KC_SLSH, KC_DEL,
        _______, _______, _______, _______, _______, _______,       KC_4,     KC_5,   KC_6,  KC_PLUS, KC_ASTR, KC_BSPC,
        _______, _______, _______, _______, _______, _______,       KC_1,     KC_2,   KC_3,  KC_DOT,  KC_EQL,  KC_ENT,
                                            _______, _______,       _______,  KC_0
    ),

    /**********************************************************************************************************
     *  LAYER 2 LAYOUT                                                                                        *
     *    Symbols                                                                                             *
     *                                                                                                        *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │    │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │   '   │   <   │   >   │   "   │   .   │    │   &   │   =>  │   [   │   ]   │   %   │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │   !   │   -   │   +   │   =   │   #   │    │   |   │   :   │   (   │   )   │   ?   │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │   ^   │   /   │   *   │   \   │  ../  │    │   ~   │   $   │   {   │   }   │   @   │       │ *
     * └───────┴───────┴───────┴───────┼───────┼───────┤    ├───────┼───────┼───────┴───────┴───────┴───────┘ *
     *                                 │       │       │    │       │       │                                 *
     *                                 │       │       │    │   _   │       │                                 *
     *                                 └───────┴───────┘    └───────┴───────┘                                 *
     **********************************************************************************************************/

    [2] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_QUOT, KC_LT,   KC_GT,   KC_DQUO, KC_DOT,         KC_AMPR, FAT_ARR, KC_LBRC, KC_RBRC, KC_PERC, _______,
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH,        KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
        _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, UP_DIR,         KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,   _______,
                                            _______, _______,        KC_UNDS, _______
    ),

    /**********************************************************************************************************
     *  LAYER 3 LAYOUT                                                                                        *
     *    Navigation                                                                                          *
     *                                                                                                        *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │   |   │   ^   │       │       │       │ *
     * │       │       │       │       │       │       │    │  <--  │   v   │   |   │  -->  │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * └───────┴───────┴───────┴───────┼───────┼───────┤    ├───────┼───────┼───────┴───────┴───────┴───────┘ *
     *                                 │       │       │    │       │       │                                 *
     *                                 │       │       │    │       │       │                                 *
     *                                 └───────┴───────┘    └───────┴───────┘                                 *
     **********************************************************************************************************/

    [3] = LAYOUT(
        RGB_TOG, QK_KB,   RGB_MOD, RGB_M_P, RGB_VAD, RGB_VAI,                      _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                      _______, KC_HOME, KC_PGUP, _______,  _______, _______,
        _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, KC_END,  KC_PGDN, _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),

    /**********************************************************************************************************
     *  LAYER 4 LAYOUT                                                                                        *
     *    System                                                                                              *
     *                                                                                                        *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │  RGB  │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  TOG  │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * └───────┴───────┴───────┴───────┼───────┼───────┤    ├───────┼───────┼───────┴───────┴───────┴───────┘ *
     *                                 │       │       │    │       │       │                                 *
     *                                 │       │       │    │       │       │                                 *
     *                                 └───────┴───────┘    └───────┴───────┘                                 *
     **********************************************************************************************************/

    [4] = LAYOUT(
        RGB_TOG, QK_KB,   RGB_MOD, RGB_M_P, RGB_VAD, RGB_VAI,                      _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, C(S(KC_TAB)), C(KC_TAB), _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),

    /**********************************************************************************************************
     *  LAYER 5 LAYOUT                                                                                        *
     *    Gaming                                                                                              *
     *                                                                                                        *
     * ┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  ESC  │   1   │   2   │   3   │   4   │   5   │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  TAB  │   Q   │   W   │   E   │   R   │   T   │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  CTL  │   A   │   S   │   D   │   F   │   G   │    │       │       │       │       │       │       │ *
     * ├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤ *
     * │       │       │       │       │       │       │    │       │       │       │       │       │       │ *
     * │  SFT  │   Z   │   X   │   C   │   V   │   B   │    │       │       │       │       │       │       │ *
     * └───────┴───────┴───────┴───────┼───────┼───────┤    ├───────┼───────┼───────┴───────┴───────┴───────┘ *
     *                                 │       │       │    │       │       │                                 *
     *                                 │ SPACE │       │    │       │       │                                 *
     *                                 └───────┴───────┘    └───────┴───────┘                                 *
     **********************************************************************************************************/

    [5] = LAYOUT(
        KC_ESC,  KC_1, KC_2, KC_3, KC_4,    KC_5,                      _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R,    KC_T,                      _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F,    KC_G,                      _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V,    KC_B,                      _______, _______, _______, _______, _______, _______,
                                   KC_SPC,  _______,          _______, _______
    ),
};
